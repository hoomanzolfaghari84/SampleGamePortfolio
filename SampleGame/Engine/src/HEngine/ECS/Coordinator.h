#pragma once

#include "ECSTypes.hpp"
#include "ComponentManager.h"
#include "EntityManager.h"
#include "SystemManager.h"

namespace HEngine {
    class EntityManager;
    class ComponentManager;
    class SystemManager;

    class HENGINE_API Coordinator {
    public:
        void Init();
        // Entity methods
        Entity CreateEntity();
        void DestroyEntity(Entity entity);

        // Component methods
        template<typename T>
        inline void RegisterComponent();

        template<typename T>
        inline void AddComponent(Entity entity, T component);

        template<typename T>
        inline void RemoveComponent(Entity entity);

        template<typename T>
        inline T& GetComponent(Entity entity);

        template<typename T>
        inline bool HasComponent(Entity entity);

        template<typename T>
        inline ComponentType GetComponentType();

        // System methods
        template<typename T>
        inline std::shared_ptr<T> RegisterSystem();

        template<typename T>
        inline void SetSystemSignature(Signature signature);

    private:
        std::unique_ptr<EntityManager> m_EntityManager;
        std::unique_ptr<ComponentManager> m_ComponentManager;
        std::unique_ptr<SystemManager> m_SystemManager;
    };


    // Component Management
    template<typename T>
    inline void Coordinator::RegisterComponent() {
        m_ComponentManager->RegisterComponent<T>();
    }

    template<typename T>
    inline void Coordinator::AddComponent(Entity entity, T component) {
        m_ComponentManager->AddComponent<T>(entity, component);

        auto signature = m_EntityManager->GetSignature(entity);
        signature.set(m_ComponentManager->GetComponentType<T>(), true);
        m_EntityManager->SetSignature(entity, signature);

        m_SystemManager->EntitySignatureChanged(entity, signature);
    }

    template<typename T>
    inline void Coordinator::RemoveComponent(Entity entity) {
        m_ComponentManager->RemoveComponent<T>(entity);

        auto signature = m_EntityManager->GetSignature(entity);
        signature.set(m_ComponentManager->GetComponentType<T>(), false);
        m_EntityManager->SetSignature(entity, signature);

        m_SystemManager->EntitySignatureChanged(entity, signature);
    }

    template<typename T>
    inline T& Coordinator::GetComponent(Entity entity) {
        return m_ComponentManager->GetComponent<T>(entity);
    }

    template<typename T>
    inline bool Coordinator::HasComponent(Entity entity) {
        return m_ComponentManager->HasComponent<T>(entity);
    }

    template<typename T>
    inline ComponentType Coordinator::GetComponentType() {
        return m_ComponentManager->GetComponentType<T>();
    }

    // System Management
    template<typename T>
    inline std::shared_ptr<T> Coordinator::RegisterSystem() {
        return m_SystemManager->RegisterSystem<T>();
    }

    template<typename T>
    inline void Coordinator::SetSystemSignature(Signature signature) {
        m_SystemManager->SetSignature<T>(signature);
    }

}
