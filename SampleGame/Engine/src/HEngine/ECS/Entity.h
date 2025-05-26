#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <string>
#include <cassert>

#include "../Core/UUID.h"
#include "Component.h"
namespace HEngine {

    class Scene;
    class EntityManager;

    class Entity {
        friend class EntityManager;

    public:
        Entity() = default;
        Entity(const Entity& other) = default;

        UUID GetUUID() const { return m_ID; }
        const std::string& GetName() const { return m_Tag; }

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args)
        {
            std::type_index type = typeid(T);
            assert(!HasComponent<T>() && "Entity already has component!");

            auto comp = std::make_unique<T>(std::forward<Args>(args)...);
            comp->entity = this;
            m_Components[type] = std::move(comp);

            return *static_cast<T*>(m_Components[type].get());
        }

        template<typename T>
        T& GetComponent()
        {
            std::type_index type = typeid(T);
            assert(HasComponent<T>() && "Entity does not have component!");
            return *static_cast<T*>(m_Components[type].get());
        }

        template<typename T>
        bool HasComponent() const
        {
            return m_Components.find(typeid(T)) != m_Components.end();
        }

        template<typename T>
        void RemoveComponent()
        {
            std::type_index type = typeid(T);
            assert(HasComponent<T>() && "Entity does not have component!");
            m_Components.erase(type);
        }

        explicit operator bool() const { return m_ID != UUID(0); }

        bool operator==(const Entity& other) const {
            return m_ID == other.m_ID && m_Scene == other.m_Scene;
        }

        bool operator!=(const Entity& other) const {
            return !(*this == other);
        }

    private:
        // Private constructor: only EntityManager can instantiate
        Entity(UUID id, Scene* scene, const std::string& tag = "Entity")
            : m_ID(id), m_Scene(scene), m_Tag(tag) {
        }

    private:
        UUID m_ID;
        std::string m_Tag;
        Scene* m_Scene = nullptr;

        std::unordered_map<std::type_index, std::unique_ptr<Component>> m_Components;
    };


}
