#pragma once

#include "..\Core\UUID.h"
#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

namespace HEngine {

	class Scene;
	class Entity;

	class EntityManager {
	public:
		EntityManager(Scene* owningScene);

		Entity* CreateEntity(const std::string& name = "Entity");

		void DestroyEntity(const UUID& id);

		Entity* GetEntity(const UUID& id);

		void ForEach(const std::function<void(Entity&)>& func);

	private:
		Scene* m_Scene;
		std::unordered_map<UUID, std::unique_ptr<Entity>> m_Entities;
	};

}
