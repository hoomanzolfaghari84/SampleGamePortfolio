#include "GameEngine.h"
#include "../ECS/Scene.h"
#include "HTime.h"


void HEngine::GameEngine::Init() {
    sf::RenderWindow m_window(sf::VideoMode({ 200, 200 }), "SFML works!");
}

void HEngine::GameEngine::Update(float dt)
{
    currentScene->Update(dt);
}


void HEngine::GameEngine::Run() {
    Init();
    sf::Clock clock;

    while (m_window.isOpen())
    {
        while (const std::optional event = m_window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                m_window.close();
        }

        float dt = clock.restart().asSeconds();
        HTime::deltaTime = dt;

        Update(dt);
        Render();
    }

}


void HEngine::GameEngine::Render() {
    m_window.clear();
    currentScene->Render(m_window);
    m_window.display();
}
