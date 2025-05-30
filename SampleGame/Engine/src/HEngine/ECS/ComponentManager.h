#pragma once
#include "ECSTypes.hpp"
#include <typeindex>
#include <cassert>
#include <bitset>

#include "Component.h"

namespace HEngine {

    class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void EntityDestroyed(Entity entity) = 0;
    };

    template<typename T>
    class ComponentArray : public IComponentArray {
    public:
        void InsertData(Entity entity, T component);
        void RemoveData(Entity entity);
        T& GetData(Entity entity);
        bool HasData(Entity entity);

        void EntityDestroyed(Entity entity) override;

    private:
        std::unordered_map<Entity, T> componentMap;
    };

    class ComponentManager {
    public:
        template<typename T>
        inline void RegisterComponent();

        template<typename T>
        inline ComponentType GetComponentType();

        template<typename T>
        inline void AddComponent(Entity entity, T component);

        template<typename T>
        inline void RemoveComponent(Entity entity);

        template<typename T>
        inline T& GetComponent(Entity entity);

        template<typename T>
        inline bool HasComponent(Entity entity);

        void EntityDestroyed(Entity entity);

    private:
        std::unordered_map<std::type_index, ComponentType> componentTypes;
        std::unordered_map<std::type_index, std::shared_ptr<IComponentArray>> componentArrays;

        ComponentType nextComponentType = 0;

        template<typename T>
        std::shared_ptr<ComponentArray<T>> GetComponentArray();
    };


    template<typename T>
    inline void HEngine::ComponentArray<T>::InsertData(HEngine::Entity entity, T component) {
        componentMap[entity] = component;
    }

    template<typename T>
    inline void HEngine::ComponentArray<T>::RemoveData(HEngine::Entity entity) {
        componentMap.erase(entity);
    }

    template<typename T>
    inline T& HEngine::ComponentArray<T>::GetData(HEngine::Entity entity) {
        assert(componentMap.find(entity) != componentMap.end() && "Component not found");
        return componentMap[entity];
    }

    template<typename T>
    inline bool HEngine::ComponentArray<T>::HasData(HEngine::Entity entity) {
        return componentMap.find(entity) != componentMap.end();
    }

    template<typename T>
    inline void HEngine::ComponentArray<T>::EntityDestroyed(HEngine::Entity entity) {
        RemoveData(entity);
    }

    // ComponentManager functions
    template<typename T>
    inline void HEngine::ComponentManager::RegisterComponent() {
        const std::type_index typeName = typeid(T);
        assert(componentTypes.find(typeName) == componentTypes.end() && "Component already registered.");
        componentTypes[typeName] = nextComponentType++;
        componentArrays[typeName] = std::make_shared<ComponentArray<T>>();
    }

    template<typename T>
    inline HEngine::ComponentType HEngine::ComponentManager::GetComponentType() {
        return componentTypes.at(typeid(T));
    }

    template<typename T>
    inline void HEngine::ComponentManager::AddComponent(HEngine::Entity entity, T component) {
        GetComponentArray<T>()->InsertData(entity, component);
    }

    template<typename T>
    inline void HEngine::ComponentManager::RemoveComponent(HEngine::Entity entity) {
        GetComponentArray<T>()->RemoveData(entity);
    }

    template<typename T>
    inline T& HEngine::ComponentManager::GetComponent(HEngine::Entity entity) {
        return GetComponentArray<T>()->GetData(entity);
    }

    template<typename T>
    inline bool HEngine::ComponentManager::HasComponent(HEngine::Entity entity) {
        return GetComponentArray<T>()->HasData(entity);
    }

    //template<typename T>
    //inline bool ComponentManager::HasComponent(Entity entity) {
    //    const std::type_index typeName = typeid(T);
    //    auto it = componentArrays.find(typeName);
    //    if (it == componentArrays.end())
    //        return false; // T hasn't been registered yet, so no entity can have it

    //    return std::static_pointer_cast<ComponentArray<T>>(it->second)->HasData(entity);
    //}

    template<typename T>
    inline std::shared_ptr<HEngine::ComponentArray<T>> HEngine::ComponentManager::GetComponentArray() {
        const std::type_index typeName = typeid(T);
        assert(componentArrays.find(typeName) != componentArrays.end() && "Component not registered.");
        return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
    }

}