#include "EntityManager.h"
#include "Entity.h"
#include "Scene.h"

namespace HEngine {

	EntityManager::EntityManager(Scene* owningScene)
		: m_Scene(owningScene) {
	}

	Entity* EntityManager::CreateEntity(const std::string& name) {
		UUID id;

		while (m_Entities.find(id) != m_Entities.end()) {
			id = UUID(); // generate again
		}

		auto entity = std::make_unique<Entity>(id, m_Scene, name);
		Entity* ptr = entity.get();
		//m_Entities.emplace(id, std::move(entity));
		m_Entities.try_emplace(id, std::move(entity));
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

	const Entity* EntityManager::GetEntity(const UUID& id) const
	{
		auto it = m_Entities.find(id);
		return it != m_Entities.end() ? it->second.get() : nullptr;
	}

	void EntityManager::ForEach(const std::function<void(Entity&)>& func) {
		for (auto& [id, e] : m_Entities)
			func(*e);
	}

	void EntityManager::ForEach(const std::function<void(const UUID&,Entity&)>& func) {
		for (auto& [id, e] : m_Entities)
			func(id, *e);
	}

	void EntityManager::ForEach(const std::function<void(const Entity&)>& func) const {
		for (const auto& [id, e] : m_Entities)
			func(*e);
	}

}
