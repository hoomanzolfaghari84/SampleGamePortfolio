#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <string>
#include <cassert>

#include "../Core/UUID.h"
#include "ComponentRegistry.h"
#include "Scene.h"
#include "EntityManager.h"


namespace HEngine {

    class UUID;
    class Scene;
    class EntityManager;
    class ComponentRegistry;
    class IComponentStorage;

    class HENGINE_API Entity {
        friend class EntityManager;

    public:
        Entity(UUID id, Scene* scene, const std::string& name)
            : m_ID(id), m_Scene(scene), m_Name(name){ }

        Entity(const Entity& other) = default;

        UUID GetUUID() const { return m_ID; }
        const std::string& GetName() const { return m_Name; }
        

        explicit operator bool() const { return m_ID != UUID(0); }

        bool operator==(const Entity& other) const {
            return m_ID == other.m_ID && m_Scene == other.m_Scene;
        }

        bool operator!=(const Entity& other) const {
            return !(*this == other);
        }

        // Template declarations
       /* template<typename T>
        T* GetComponent();

        template<typename T>
        void AddComponent(T component);*/

    private:
        UUID m_ID;
        Scene* m_Scene;
        std::string m_Name;

    };

    // Template definitions (inline, outside class)
    /*template<typename T>
    inline T* Entity::GetComponent() {
        static_assert(std::is_class_v<T>, "Component type must be a class");
        return m_Scene->GetComponentRegistry().Get<T>(m_ID);
    }

    template<typename T>
    inline void Entity::AddComponent(T component) {
        static_assert(std::is_class_v<T>, "Component type must be a class");
        static_assert(std::is_move_constructible_v<T>, "Component must be move-constructible");

        m_Scene->GetComponentRegistry().Add<T>(m_ID, std::move(component));
    }*/

}
