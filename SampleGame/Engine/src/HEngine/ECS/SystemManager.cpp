#include "hepch.h"
#include "SystemManager.h"
#include <cassert>


void HEngine::SystemManager::EntityDestroyed(HEngine::Entity entity) {
    for (auto const& pair : systems) {
        pair.second->m_Entities.erase(entity);
    }
}

void HEngine::SystemManager::EntitySignatureChanged(HEngine::Entity entity, HEngine::Signature entitySignature) {
    for (auto const& pair : systems) {
        const auto& type = pair.first;
        const auto& system = pair.second;
        const auto& systemSignature = signatures[type];

        if ((entitySignature & systemSignature) == systemSignature) {
            system->m_Entities.insert(entity);
        }
        else {
            system->m_Entities.erase(entity);
        }
    }
}
