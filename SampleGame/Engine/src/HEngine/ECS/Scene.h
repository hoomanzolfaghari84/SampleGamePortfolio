#pragma once

#include "Coordinator.h"
#include "HEngine/Core/Core.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <memory>



namespace HEngine {

    enum class SceneState {
        Active,
        Paused,
        Inactive
    };

    class HENGINE_API Scene {
    public:
        Scene(const std::string& name) : m_Name(name) {};
        virtual ~Scene() = default;

        virtual void OnCreate() = 0;
        virtual void OnUpdate(float dt) = 0;
        virtual void OnRender(sf::RenderWindow& window) = 0;
        virtual void OnDestroy() {}

        const std::string& GetName() const { return m_Name; }

        SceneState GetState() const { return m_State; }
        void SetState(SceneState state) { m_State = state; }

        Coordinator& GetCoordinator() { return *m_Coordinator; }
		//const Coordinator& GetCoordinator() const { return *m_Coordinator; }

    protected:
        std::string m_Name;
        std::unique_ptr<Coordinator> m_Coordinator;
        SceneState m_State = SceneState::Active;
    };

}
