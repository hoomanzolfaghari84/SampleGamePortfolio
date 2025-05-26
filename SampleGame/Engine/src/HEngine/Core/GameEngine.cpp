#include "GameEngine.h"
#include "Scene.h"
#include "HTime.h"


void GameEngine::Init() {
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    currentScene = new SampleScene();
    currentScene->Init();
}

void GameEngine::Init(Scene* initScene) {
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    currentScene = initScene;
    currentScene->Init();
}

void GameEngine::Run() {
    Init();
    sf::Clock clock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();
        HTime::deltaTime = dt;

        currentScene->Update(dt);
        window.clear();
        currentScene->Render(window);
        window.display();
    }

}
