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

    class HENGINE_API Entity {
        friend class EntityManager;

    public:
        Entity(UUID id, Scene* scene, const std::string& name)
            : m_ID(id), m_Scene(scene), m_Name(name){ }

        Entity(const Entity& other) = default;

        UUID GetUUID() const { return m_ID; }
        const std::string& GetName() const { return m_Name; }


        /*template<typename T, typename... Args>
        T& AddComponent(Args&&... args);
        

        template<typename T>
        T& GetComponent();
        

        template<typename T>
        bool HasComponent() const;

        template<typename T>
        void RemoveComponent();*/
        

        explicit operator bool() const { return m_ID != UUID(0); }

        bool operator==(const Entity& other) const {
            return m_ID == other.m_ID && m_Scene == other.m_Scene;
        }

        bool operator!=(const Entity& other) const {
            return !(*this == other);
        }

        template<typename T>
        T* GetComponent();

        template<typename T>
        void AddComponent(T component);

    private:
        UUID m_ID;
        Scene* m_Scene;
        std::string m_Name;

        

        //std::unordered_map<std::type_index, std::unique_ptr<Component>> m_Components;
    };

}
