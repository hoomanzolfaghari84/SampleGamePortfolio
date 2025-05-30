#include "hepch.h"
#include "Coordinator.h"
#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"

namespace HEngine {
    void Coordinator::Init() {
        m_EntityManager = std::make_unique<EntityManager>();
        m_ComponentManager = std::make_unique<ComponentManager>();
        m_SystemManager = std::make_unique<SystemManager>();
    }

    Entity Coordinator::CreateEntity() {
        Entity entity = m_EntityManager->CreateEntity();
        if (entity >= MAX_ENTITIES) {
            throw std::out_of_range("Entities have reached MAX_ENTITIES");
        }
        AddComponent(entity, IDComponent{}); // Auto-attach UUID
        return entity;
    }

    void Coordinator::DestroyEntity(Entity entity) {
        if (entity >= MAX_ENTITIES) {
            throw std::out_of_range("Invalid Entity ID");
        }
        m_EntityManager->DestroyEntity(entity);
        m_ComponentManager->EntityDestroyed(entity);
        m_SystemManager->EntityDestroyed(entity);
    }

    //// Template function definitions (must be in header, so empty here)
    //template void Coordinator::RegisterComponent<TransformComponent>();
    //template void Coordinator::AddComponent<TransformComponent>(Entity, TransformComponent);
    //template void Coordinator::RemoveComponent<TransformComponent>(Entity);
    //template TransformComponent& Coordinator::GetComponent<TransformComponent>(Entity);
    //template bool Coordinator::HasComponent<TransformComponent>(Entity);
    //template ComponentType Coordinator::GetComponentType<TransformComponent>();
    //template void Coordinator::RegisterComponent<RectangleComponent>();
    //template void Coordinator::AddComponent<RectangleComponent>(Entity, RectangleComponent);
    //template void Coordinator::RemoveComponent<RectangleComponent>(Entity);
    //template RectangleComponent& Coordinator::GetComponent<RectangleComponent>(Entity);
    //template bool Coordinator::HasComponent<RectangleComponent>(Entity);
    //template ComponentType Coordinator::GetComponentType<RectangleComponent>();
    //template void Coordinator::RegisterComponent<TextComponent>();
    //template void Coordinator::AddComponent<TextComponent>(Entity, TextComponent);
    //template void Coordinator::RemoveComponent<TextComponent>(Entity);
    //template TextComponent& Coordinator::GetComponent<TextComponent>(Entity);
    //template bool Coordinator::HasComponent<TextComponent>(Entity);
    //template ComponentType Coordinator::GetComponentType<TextComponent>();
    //template void Coordinator::RegisterComponent<SpriteComponent>();
    //template void Coordinator::AddComponent<SpriteComponent>(Entity, SpriteComponent);
    //template void Coordinator::RemoveComponent<SpriteComponent>(Entity);
    //template SpriteComponent& Coordinator::GetComponent<SpriteComponent>(Entity);
    //template bool Coordinator::HasComponent<SpriteComponent>(Entity);
    //template ComponentType Coordinator::GetComponentType<SpriteComponent>();
    //template void Coordinator::RegisterComponent<IDComponent>();
    //template void Coordinator::AddComponent<IDComponent>(Entity, IDComponent);
    //template void Coordinator::RemoveComponent<IDComponent>(Entity);
    //template IDComponent& Coordinator::GetComponent<IDComponent>(Entity);
    //template bool Coordinator::HasComponent<IDComponent>(Entity);
    //template ComponentType Coordinator::GetComponentType<IDComponent>();
}