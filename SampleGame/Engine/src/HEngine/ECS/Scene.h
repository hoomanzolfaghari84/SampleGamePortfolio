#pragma once

#include "HEngine/Core/Core.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <memory>
#include "HECS.hpp"
#include "HEngine/Renderer/RenderAPI.h"
#include "HEngine/Core/Timestep.h"



namespace HEngine {
    

    enum class SceneState {
        Active,
        Paused,
        Inactive
    };

    class HENGINE_API Scene {
    public:
        Scene(const std::string& name) : m_Name(name) {
            m_RenderQueue = std::make_unique<HRenderQueue>();
            m_Coordinator = std::make_unique<ECS::Coordinator>();
        };
        virtual ~Scene() = default;

        virtual void OnCreate() = 0;
        virtual void OnUpdate(HTimestep ts) {
            HEngine::ECS::SystemContext ctx(ts, *m_Coordinator, *m_RenderQueue );
            m_Coordinator->UpdateAllSystems(ctx);
        }
        virtual void OnRender(HRenderAPI& renderer) { m_RenderQueue->ExecuteAll(renderer); }
        virtual void OnDestroy() {}

        const std::string& GetName() const { return m_Name; }

        SceneState GetState() const { return m_State; }
        void SetState(SceneState state) { m_State = state; }

        HEngine::ECS::Coordinator& GetCoordinator() { return *m_Coordinator; }
		//const Coordinator& GetCoordinator() const { return *m_Coordinator; }

    protected:
        std::string m_Name;
        std::unique_ptr<HEngine::HRenderQueue> m_RenderQueue;
        std::unique_ptr<HEngine::ECS::Coordinator> m_Coordinator;
        SceneState m_State = SceneState::Active;
    };

}
