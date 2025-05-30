#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "Core.h";
#include "HEngine/ECS/Scene.h"

namespace HEngine {

    class HENGINE_API GameEngine {
    public:
        GameEngine();
        ~GameEngine();

        void Init();
        void Run();
        void Shutdown();

        void AddScene(std::shared_ptr<Scene> scene);
        void RemoveScene(const std::string& name);
        std::shared_ptr<Scene> GetScene(const std::string& name);

    private:
        sf::RenderWindow m_Window;
        std::unordered_map<std::string, std::shared_ptr<Scene>> m_Scenes;
        std::vector<std::string> m_ActiveSceneNames;

        bool m_Running = false;
        float m_DeltaTime = 0.0f;
    };
}
