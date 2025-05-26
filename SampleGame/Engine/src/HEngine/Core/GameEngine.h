#pragma once

#include <SFML/Graphics.hpp>
#include "../ECS/Entity.h"
namespace HEngine {

    class GameEngine {
    public:
        void Run();

    private:
        sf::RenderWindow m_window;
        Scene* currentScene = nullptr;

        void Init();
        void Update(float dt);
        void Render();
    };
}
