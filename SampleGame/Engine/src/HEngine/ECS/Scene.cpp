#include "Scene.h"
#include "Entity.h"

namespace HEngine {

	Scene::Scene()
		: m_EntityManager(this) {
	}

	Entity* Scene::CreateEntity(const std::string& name) {
		return m_EntityManager.CreateEntity(name);
	}

	void Scene::DestroyEntity(UUID id) {
		m_EntityManager.DestroyEntity(id);
	}

	ComponentRegistry& Scene::GetComponentRegistry() {
		return m_ComponentRegistry;
	}

	EntityManager& Scene::GetEntityManager() {
		return m_EntityManager;
	}

	//void Scene::Update(float dt) {
	//	// Game logic updates
	//}

	//void Scene::Render(sf::RenderWindow& window) {
	//	// Render the scene
	//}

}
