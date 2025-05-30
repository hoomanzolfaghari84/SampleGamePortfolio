#include "hepch.h"
#include "EntityManager.h"
#include <cassert>

HEngine::EntityManager::EntityManager() {
    for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
        availableEntities.push(entity);
    }
}

HEngine::Entity HEngine::EntityManager::CreateEntity() {
    assert(livingEntityCount < MAX_ENTITIES && "Too many entities in existence.");
    Entity id = availableEntities.front();
    availableEntities.pop();
    ++livingEntityCount;
    return id;
}

void HEngine::EntityManager::DestroyEntity(HEngine::Entity entity) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");
    signatures[entity].reset();
    availableEntities.push(entity);
    --livingEntityCount;
}

void HEngine::EntityManager::SetSignature(HEngine::Entity entity, HEngine::Signature signature) {
    assert(entity < MAX_ENTITIES);
    signatures[entity] = signature;
}

HEngine::Signature HEngine::EntityManager::GetSignature(HEngine::Entity entity) const {
    assert(entity < MAX_ENTITIES);
    return signatures[entity];
}
