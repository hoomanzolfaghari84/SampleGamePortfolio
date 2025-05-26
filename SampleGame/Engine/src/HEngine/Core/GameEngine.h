#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"

class GameEngine {
public:
    void Run();

private:
    sf::RenderWindow window;
    Scene* currentScene = nullptr;

    void Init();
    void Update(float dt);
    void Render();
};
