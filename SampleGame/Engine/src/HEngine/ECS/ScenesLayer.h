#pragma once
#include "HEngine/Core/Layer.h"
#include "Scene.h"

namespace HEngine {

    class ScenesLayer : public Layer {
    public:
        ScenesLayer() : Layer("ScenesLayer") {}

        void RegisterScene(std::shared_ptr<Scene> scene) {
            m_Scenes.emplace_back(scene);
        }

        void OnUpdate(HTimestep ts) override {
            for (auto& scene : m_Scenes)
                if(scene->GetState() == SceneState::Active)
                    scene->OnUpdate(ts);

        }

        void OnRender(HRenderAPI& renderer) override {
            for (auto& scene : m_Scenes)
                if (scene->GetState() == SceneState::Active || scene->GetState()==SceneState::Paused)
                    scene->OnRender(renderer);
        }

    private:
        std::vector<std::shared_ptr<Scene>> m_Scenes;
    };

}
