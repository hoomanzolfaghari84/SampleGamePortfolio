#pragma once

#include "EntityManager.h"
#include "ComponentRegistry.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include "../Initializations/Core.h"

namespace HEngine {

	class Entity;
	class EntityManager;
	

	class HENGINE_API Scene {
	public:
		Scene();
		virtual ~Scene() = default;

		Entity* CreateEntity(const std::string& name = "Entity");
		void DestroyEntity(UUID id);

		ComponentRegistry& GetComponentRegistry();
		EntityManager& GetEntityManager();

		virtual void Update(float dt) = 0;
		virtual void Render(sf::RenderWindow& window) = 0;

	private:
		ComponentRegistry m_ComponentRegistry;
		EntityManager m_EntityManager;

		/*std::shared_ptr<ComponentRegistry> m_ComponentRegistry;
		std::shared_ptr<EntityManager> m_EntityManager;*/
	};

}
