// EntityManager.h
#pragma once
#include <vector>
#include <memory>
#include "Entity.h"
#include "../Core/UUID.h"
#include "../Core/Scene.h"

#include <functional> 

namespace HEngine  {
    class EntityManager {
    public:
        EntityManager(Scene* owningScene)
            : m_Scene(owningScene) {
        }

        Entity* CreateEntity(const std::string& name = "Entity") {
            UUID id;
            auto entity = std::make_unique<Entity>(id, m_Scene, name);
            Entity* ptr = entity.get();
            m_Entities.push_back(std::move(entity));
            return ptr;
        }


        void ForEach(const std::function<void(Entity&)>& func) {
            for (auto& e : m_Entities)
                func(*e);
        }

    private:
        Scene* m_Scene;
        std::vector<std::unique_ptr<Entity>> m_Entities;
    };
}