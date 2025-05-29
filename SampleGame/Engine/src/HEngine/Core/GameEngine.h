#pragma once

#include <SFML/Graphics.hpp>
#include "../ECS/Entity.h"
#include "../ECS/RenderSystem.h"
namespace HEngine {

    class GameEngine {
    public:
        GameEngine(unsigned int width = 800, unsigned int height = 600, const std::string& title = "HEngine Window");
        void Run();
        void ChangeScene(std::unique_ptr<Scene> newScene);

    private:
        sf::RenderWindow m_window;
        std::unique_ptr<Scene> currentScene;
        std::unique_ptr<RenderSystem> renderSystem;

        void Init();
        void ProcessEvents();
        void Update(float dt);
        void Render();
    };
}
