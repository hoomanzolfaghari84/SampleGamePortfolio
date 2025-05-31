#include "hepch.h"
#include "GameEngine.h"
#include <chrono>
#include "HEngine/ECS/ScenesLayer.h"
#include "HEngine/Renderer/RenderAPI.h"
#include "HEngine/Renderer/SFMLRenderAPI.h"

HEngine::GameEngine::GameEngine()
    : m_Window(sf::VideoMode({1280, 720}), "HEngine Game") {
}

HEngine::GameEngine::~GameEngine() {
    Shutdown();
}

void HEngine::GameEngine::Init() {

    HEngine::ScenesLayer* sceneLayer = new ScenesLayer();
    // Initialize scenes
    for (auto& scene : m_Scenes) {
        sceneLayer->RegisterScene(scene);
    }
    m_LayerStack.PushLayer(sceneLayer);

    m_Running = true;
}

void HEngine::GameEngine::Run() {
    using clock = std::chrono::high_resolution_clock;
    HRenderAPI* renderer = new SFMLRenderAPI(m_Window);

    while (m_Window.isOpen() && m_Running) {
        auto start = clock::now();

        while (const std::optional event = m_Window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
            {
                m_Window.close();
            }
                
        }

        HTimestep ts(m_DeltaTime);

        for (auto* layer : m_LayerStack)
            layer->OnUpdate(ts);

        renderer->BeginFrame();
        renderer->Clear(HColor::Black);

        for (auto* layer : m_LayerStack)
            layer->OnRender(*renderer);

        renderer->EndFrame();
        renderer->Present();

        auto end = clock::now();
        m_DeltaTime = std::chrono::duration<float>(end - start).count();
    }

    delete renderer;
}

void HEngine::GameEngine::Shutdown() {
    HE_CORE_INFO("Shutting Down Engine");
    //delete &m_LayerStack;
}

void HEngine::GameEngine::AddScene(std::shared_ptr<HEngine::Scene> scene) {
    m_Scenes.push_back(scene);
}

//void HEngine::GameEngine::RemoveScene(const std::string& name) {
//    m_Scenes.erase(name);
//    m_ActiveSceneNames.erase(
//        std::remove(m_ActiveSceneNames.begin(), m_ActiveSceneNames.end(), name),
//        m_ActiveSceneNames.end());
//}


