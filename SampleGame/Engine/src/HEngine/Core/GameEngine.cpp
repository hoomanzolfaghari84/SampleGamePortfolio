#include "GameEngine.h"
#include "../ECS/Scene.h"
#include "HTime.h"


HEngine::GameEngine::GameEngine(unsigned int width, unsigned int height, const std::string& title) {
    m_window.create(sf::VideoMode({width, height}), title);
    m_window.setFramerateLimit(60); // Optional: Lock to 60 FPS

    renderSystem = std::make_unique<RenderSystem>(m_window);
}

void HEngine::GameEngine::Init() {
    // Any additional one-time initialization (e.g., logging, asset loading) can go here
}

void HEngine::GameEngine::ChangeScene(std::unique_ptr<Scene> newScene) {
    currentScene = std::move(newScene);
}

void HEngine::GameEngine::ProcessEvents() {

    while (const std::optional event = m_window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            m_window.close();

        //if (currentScene) {
        //    currentScene->HandleEvent(event);  // If your Scene supports input
        //}

    }

    
}

void HEngine::GameEngine::Update(float dt) {
    if (currentScene) {
        currentScene->Update(dt);
    }
}

void HEngine::GameEngine::Render() {
    m_window.clear();

    if (currentScene) {
        currentScene->Render(m_window);
    }

    renderSystem->Update(currentScene->GetEntityManager(), currentScene->GetComponentRegistry(),0);

    m_window.display();
}

void HEngine::GameEngine::Run() {
    Init();
    sf::Clock clock;

    while (m_window.isOpen()) {
        ProcessEvents();

        float dt = clock.restart().asSeconds();
        HTime::deltaTime = dt;

        Update(dt);
        Render();
    }
}