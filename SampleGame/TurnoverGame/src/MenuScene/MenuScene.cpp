#include "MenuScene.h"
#include <iostream>



//300.f, 150.f, 200.f, 60.f

MenuScene::MenuScene() : HEngine::Scene("MenuScene")
{
	
}



void MenuScene::OnCreate()
{
	m_Coordinator = std::make_unique<HEngine::Coordinator>();
	m_Coordinator->Init();

	m_rect_render_sys = m_Coordinator->RegisterSystem<HEngine::RectangleRenderSystem>(*m_Coordinator);
	m_Coordinator->RegisterComponent<HEngine::RectangleComponent>();

	HEngine::Signature signature;
	signature.set(m_Coordinator->GetComponentType<HEngine::RectangleComponent>());
	m_Coordinator->SetSystemSignature<HEngine::RectangleRenderSystem>(signature);

	HEngine::Entity start_btn = m_Coordinator->CreateEntity();
	HEngine::RectangleComponent s_rec;
	s_rec.position = { 300.0f, 150.0f };
	s_rec.size = { 200.0f, 100.0f };
	s_rec.color = HEngine::HColor::Green;
	m_Coordinator->AddComponent<HEngine::RectangleComponent>(start_btn, s_rec);

	HEngine::Entity exit_btn = m_Coordinator->CreateEntity();
	HEngine::RectangleComponent e_rec;
	s_rec.position = { 300.0f, 300.0f };
	s_rec.size = { 200.0f, 100.0f };
	s_rec.color = HEngine::HColor::Blue;
	m_Coordinator->AddComponent<HEngine::RectangleComponent>(exit_btn, e_rec);
	
}

void MenuScene::OnUpdate(float dt)
{
	
}

void MenuScene::OnRender(sf::RenderWindow& window)
{
	HE_INFO("Redering Rectangles");
	m_rect_render_sys->Render(window);
}
