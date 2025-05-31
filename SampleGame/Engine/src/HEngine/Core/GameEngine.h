#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "Core.h";
#include "HEngine/ECS/Scene.h"
#include "LayerStack.h"

namespace HEngine {

    class HENGINE_API GameEngine {
    public:
        GameEngine();
        ~GameEngine();

        void Init();
        void Run();
        void Shutdown();

        void AddScene(std::shared_ptr<Scene> scene);
        //void RemoveScene(const std::string& name);

    private:
        sf::RenderWindow m_Window;
        //HRenderAPI* m_Renderer = nullptr;

        LayerStack m_LayerStack;
        std::vector<std::shared_ptr<Scene>> m_Scenes;

        bool m_Running = false;
        float m_DeltaTime = 0.0f;
    };
}
