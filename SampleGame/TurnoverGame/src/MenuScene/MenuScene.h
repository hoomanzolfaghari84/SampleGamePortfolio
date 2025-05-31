#pragma once

#include <HEngine.h>


class MenuScene : public HEngine::Scene {
public:
    MenuScene() : HEngine::Scene("MenuScene") {
        OnCreate();
    }

    void OnCreate() override {
        m_Coordinator->Init();
        //m_Coordinator.RegisterComponent<HEngine::Transform2DComponent>();
        m_Coordinator->RegisterComponent<HEngine::RectangleComponent>();
        m_Coordinator->RegisterSystem<HEngine::RectangleRenderSystem>();

        // Start Button
        auto startBtn = m_Coordinator->CreateEntity();
        auto rect_c = HEngine::RectangleComponent();
        rect_c.position = { 300.0f, 150.0f };
        rect_c.color = HEngine::HColor::Green;
        rect_c.size = { 200.0f, 150.0f };
        m_Coordinator->AddComponent(startBtn, rect_c);

        // Exit Button
        auto exitBtn = m_Coordinator->CreateEntity();
        auto rect_ce = HEngine::RectangleComponent();
        rect_ce.position = { 300.0f, 300.0f };
        rect_ce.color = HEngine::HColor::Blue;
        rect_ce.size = { 150.0f, 100.0f };
        m_Coordinator->AddComponent(exitBtn, rect_ce);

    }

    //void OnUpdate(HEngine::HTimestep ts) override {
    //    // Add animation or hover detection if needed
    //}

    /*void OnRender(HEngine::HRenderAPI& renderer) override {
        
    }*/


};