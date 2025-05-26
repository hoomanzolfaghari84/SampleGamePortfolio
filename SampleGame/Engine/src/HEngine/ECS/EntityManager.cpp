#include "EntityManager.h"
#include "Entity.h"
#include "Scene.h"

namespace HEngine {

	EntityManager::EntityManager(Scene* owningScene)
		: m_Scene(owningScene) {
	}

	Entity* EntityManager::CreateEntity(const std::string& name) {
		UUID id;
		auto entity = std::make_unique<Entity>(id, m_Scene, name);
		Entity* ptr = entity.get();
		m_Entities.emplace(id, std::move(entity));
		return ptr;
	}

	void EntityManager::DestroyEntity(const UUID& id) {
		auto it = m_Entities.find(id);
		if (it != m_Entities.end()) {
			m_Scene->GetComponentRegistry().RemoveAllComponents(id);
			m_Entities.erase(it);
		}
	}

	Entity* EntityManager::GetEntity(const UUID& id) {
		auto it = m_Entities.find(id);
		return it != m_Entities.end() ? it->second.get() : nullptr;
	}

	void EntityManager::ForEach(const std::function<void(Entity&)>& func) {
		for (auto& [id, e] : m_Entities)
			func(*e);
	}

}
