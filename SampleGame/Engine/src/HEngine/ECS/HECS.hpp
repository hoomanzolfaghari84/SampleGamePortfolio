#pragma once

#include <array>
#include <bitset>
#include <memory>
#include <queue>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstdint>
#include <functional>
#include <optional>

#include "HEngine\Core\Core.h"
#include "HEngine\Core\Timestep.h"
#include <HEngine/Renderer/RenderQueue.h>

namespace HEngine::ECS {

    using Entity = std::uint32_t;
    constexpr Entity MAX_ENTITIES = 5000;
    constexpr std::size_t MAX_COMPONENTS = 64;
    using Signature = std::bitset<MAX_COMPONENTS>;

    class HENGINE_API EntityManager {
    public:
        EntityManager() {
            for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
                availableEntities.push(entity);
            }
        }

        Entity CreateEntity() {
            assert(livingEntityCount < MAX_ENTITIES && "Too many entities.");
            Entity id = availableEntities.front();
            availableEntities.pop();
            ++livingEntityCount;
            return id;
        }

        void DestroyEntity(Entity entity) {
            assert(entity < MAX_ENTITIES && "Entity out of range.");
            availableEntities.push(entity);
            --livingEntityCount;
            signatures[entity].reset();
        }

        void SetSignature(Entity entity, Signature signature) {
            signatures[entity] = signature;
        }

        Signature GetSignature(Entity entity) const {
            return signatures[entity];
        }

    private:
        std::queue<Entity> availableEntities;
        std::array<Signature, MAX_ENTITIES> signatures{};
        uint32_t livingEntityCount = 0;
    };

    class ComponentTypeManager {
    public:
        template<typename T>
        static std::size_t GetTypeID() {
            static std::size_t typeID = nextID++;
            assert(typeID < MAX_COMPONENTS && "Too many component types.");
            return typeID;
        }

    private:
        static inline std::size_t nextID = 0;
    };

    template<typename T>
    class ComponentArray {
    public:
        void InsertData(Entity entity, const T& component) {
            entityToIndex[entity] = size;
            indexToEntity[size] = entity;
            components[size] = component;
            ++size;
        }

        void RemoveData(Entity entity) {
            size_t index = entityToIndex[entity];
            size_t lastIndex = size - 1;

            components[index] = components[lastIndex];
            Entity lastEntity = indexToEntity[lastIndex];

            entityToIndex[lastEntity] = index;
            indexToEntity[index] = lastEntity;

            entityToIndex.erase(entity);
            indexToEntity.erase(lastIndex);
            --size;
        }

        T& GetData(Entity entity) {
            return components[entityToIndex[entity]];
        }

        bool HasData(Entity entity) const {
            return entityToIndex.find(entity) != entityToIndex.end();
        }

    private:
        std::array<T, MAX_ENTITIES> components;
        std::unordered_map<Entity, size_t> entityToIndex;
        std::unordered_map<size_t, Entity> indexToEntity;
        size_t size = 0;
    };

    class HENGINE_API ComponentManager {
    public:
        template<typename T>
        void RegisterComponent() {
            const std::size_t typeID = ComponentTypeManager::GetTypeID<T>();
            if (componentArrays.find(typeID) == componentArrays.end()) {
                componentArrays[typeID] = std::make_shared<ComponentArray<T>>();
            }
        }

        template<typename T>
        void AddComponent(Entity entity, const T& component) {
            GetComponentArray<T>()->InsertData(entity, component);
        }

        template<typename T>
        void RemoveComponent(Entity entity) {
            GetComponentArray<T>()->RemoveData(entity);
        }

        template<typename T>
        T& GetComponent(Entity entity) {
            return GetComponentArray<T>()->GetData(entity);
        }

        template<typename T>
        bool HasComponent(Entity entity) const {
            return GetComponentArray<T>()->HasData(entity);
        }

    private:
        std::unordered_map<std::size_t, std::shared_ptr<void>> componentArrays;

        template<typename T>
        std::shared_ptr<ComponentArray<T>> GetComponentArray() const {
            std::size_t typeID = ComponentTypeManager::GetTypeID<T>();
            return std::static_pointer_cast<ComponentArray<T>>(componentArrays.at(typeID));
        }
    };

    class HENGINE_API Coordinator; // Forward declare for System

    struct SystemContext {
        HEngine::HTimestep ts;
        HEngine::ECS::Coordinator& coordinator;
        HEngine::HRenderQueue& renderQueue; //TODO make optional

        SystemContext(HEngine::HTimestep ts,
        HEngine::ECS::Coordinator& coordinator,
        HEngine::HRenderQueue& renderQueue) : ts(ts), coordinator(coordinator), renderQueue(renderQueue)
        {

        }
    };

    class HENGINE_API System {
    public:
        virtual ~System() = default;
        virtual void Update(const SystemContext& ctx) = 0;
        std::unordered_set<Entity> entities;
    };

    class HENGINE_API SystemManager {
    public:
        template<typename T>
        std::shared_ptr<T> RegisterSystem() {
            const char* typeName = typeid(T).name();
            assert(systems.find(typeName) == systems.end() && "System already registered.");
            auto system = std::make_shared<T>();
            systems[typeName] = system;
            return system;
        }

        template<typename T>
        void SetSignature(Signature signature) {
            const char* typeName = typeid(T).name();
            signatures[typeName] = signature;
        }

        void EntityDestroyed(Entity entity) {
            for (auto& [_, system] : systems) {
                system->entities.erase(entity);
            }
        }

        void EntitySignatureChanged(Entity entity, Signature entitySig) {
            for (auto& [type, system] : systems) {
                const auto& sig = signatures[type];
                if ((entitySig & sig) == sig)
                    system->entities.insert(entity);
                else
                    system->entities.erase(entity);
            }
        }

        const std::unordered_map<const char*, std::shared_ptr<System>>& GetSystems() const {
            return systems;
        }

    private:
        std::unordered_map<const char*, Signature> signatures;
        std::unordered_map<const char*, std::shared_ptr<System>> systems;
    };

    class HENGINE_API Coordinator {
    public:
        void Init() {
            entityManager = std::make_unique<EntityManager>();
            componentManager = std::make_unique<ComponentManager>();
            systemManager = std::make_unique<SystemManager>();
        }

        Entity CreateEntity() {
            return entityManager->CreateEntity();
        }

        void DestroyEntity(Entity entity) {
            entityManager->DestroyEntity(entity);
            systemManager->EntityDestroyed(entity);
        }

        template<typename T>
        void RegisterComponent() {
            componentManager->RegisterComponent<T>();
        }

        template<typename T>
        void AddComponent(Entity entity, const T& component) {
            componentManager->AddComponent<T>(entity, component);
            auto signature = entityManager->GetSignature(entity);
            signature.set(ComponentTypeManager::GetTypeID<T>(), true);
            entityManager->SetSignature(entity, signature);
            systemManager->EntitySignatureChanged(entity, signature);
        }

        template<typename T>
        void RemoveComponent(Entity entity) {
            componentManager->RemoveComponent<T>(entity);
            auto signature = entityManager->GetSignature(entity);
            signature.set(ComponentTypeManager::GetTypeID<T>(), false);
            entityManager->SetSignature(entity, signature);
            systemManager->EntitySignatureChanged(entity, signature);
        }

        template<typename T>
        T& GetComponent(Entity entity) {
            return componentManager->GetComponent<T>(entity);
        }

        template<typename T>
        bool HasComponent(Entity entity) const {
            return componentManager->HasComponent<T>(entity);
        }

        template<typename T>
        std::shared_ptr<T> RegisterSystem() {
            return systemManager->RegisterSystem<T>();
        }

        template<typename T>
        void SetSystemSignature(Signature signature) {
            systemManager->SetSignature<T>(signature);
        }

        void UpdateAllSystems(const SystemContext& ctx) {
            for (const auto& [_, system] : systemManager->GetSystems()) {
                system->Update(ctx);
            }
        }

    private:
        std::unique_ptr<EntityManager> entityManager;
        std::unique_ptr<ComponentManager> componentManager;
        std::unique_ptr<SystemManager> systemManager;
    };

} // namespace HEngine::ECS
