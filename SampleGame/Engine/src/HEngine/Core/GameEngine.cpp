#include "hepch.h"
#include "GameEngine.h"
#include <chrono>

HEngine::GameEngine::GameEngine()
    : m_Window(sf::VideoMode({1280, 720}), "HEngine Game") {
}

HEngine::GameEngine::~GameEngine() {
    Shutdown();
}

void HEngine::GameEngine::Init() {
    m_Running = true;

    // Initialize scenes
    for (auto& [name, scene] : m_Scenes) {
        scene->OnCreate();
    }
}

void HEngine::GameEngine::Run() {
    using clock = std::chrono::high_resolution_clock;

    while (m_Window.isOpen() && m_Running) {
        auto start = clock::now();

        while (const std::optional event = m_Window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
                m_Window.close();
        }

        m_Window.clear();

        // Update and render scenes
        for (const auto& name : m_ActiveSceneNames) {
            auto scene = GetScene(name);
            if (!scene) continue;

            switch (scene->GetState()) {
            case SceneState::Active:
                scene->OnUpdate(m_DeltaTime);
                scene->OnRender(m_Window);
                break;
            case SceneState::Paused:
                scene->OnRender(m_Window);  // still render
                break;
            case SceneState::Inactive:
                break;
            }
        }

        m_Window.display();

        auto end = clock::now();
        m_DeltaTime = std::chrono::duration<float>(end - start).count();
    }
}

void HEngine::GameEngine::Shutdown() {
    for (auto& [name, scene] : m_Scenes) {
        scene->OnDestroy();
    }
    m_Scenes.clear();
    m_ActiveSceneNames.clear();
}

void HEngine::GameEngine::AddScene(std::shared_ptr<HEngine::Scene> scene) {
    const auto& name = scene->GetName();
    m_Scenes[name] = scene;
    m_ActiveSceneNames.push_back(name);
}

void HEngine::GameEngine::RemoveScene(const std::string& name) {
    m_Scenes.erase(name);
    m_ActiveSceneNames.erase(
        std::remove(m_ActiveSceneNames.begin(), m_ActiveSceneNames.end(), name),
        m_ActiveSceneNames.end());
}

std::shared_ptr<HEngine::Scene> HEngine::GameEngine::GetScene(const std::string& name) {
    if (m_Scenes.find(name) != m_Scenes.end())
        return m_Scenes[name];
    return nullptr;
}
