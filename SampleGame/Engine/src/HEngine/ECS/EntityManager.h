#pragma once

#include "..\Core\UUID.h"
#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

#include "../Initializations/Core.h"

namespace HEngine {

	class Scene;
	class Entity;

	class HENGINE_API EntityManager {
	public:

		EntityManager(Scene* owningScene);
		EntityManager(EntityManager&&) noexcept = default; // Allow move constructor
		EntityManager& operator=(EntityManager&&) noexcept = delete; // Disable move assignment
		EntityManager(const EntityManager&) = delete;
		EntityManager& operator=(const EntityManager&) = delete;


		Entity* CreateEntity(const std::string& name = "Entity");

		void DestroyEntity(const UUID& id);

		Entity* GetEntity(const UUID& id);
		const Entity* GetEntity(const UUID& id) const;

		void ForEach(const std::function<void(Entity&)>& func);
		void ForEach(const std::function<void(const UUID&, Entity&)>& func);
		void ForEach(const std::function<void(const Entity&)>& func) const;

		//// Prevent copy
		//EntityManager(const EntityManager&) = delete;
		//EntityManager& operator=(const EntityManager&) = delete;

		//// Allow move
		//EntityManager(EntityManager&&) noexcept = default;
		//EntityManager& operator=(EntityManager&&) noexcept = default;

	private:
		Scene* m_Scene;
		std::unordered_map<UUID, std::unique_ptr<Entity>> m_Entities;
	};

}
