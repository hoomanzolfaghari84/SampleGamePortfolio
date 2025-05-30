#include "hepch.h"
#include "ComponentManager.h"


void HEngine::ComponentManager::EntityDestroyed(HEngine::Entity entity) {
    for (auto const& pair : componentArrays) {
        pair.second->EntityDestroyed(entity);
    }
}
