#include "MenuScene.h"
#include <iostream>



//300.f, 150.f, 200.f, 60.f

MenuScene::MenuScene() : HEngine::Scene("MenuScene")
{
	
}


void MenuScene::OnCreate()
{
	m_Coordinator = std::make_shared<HEngine::Coordinator>();
	m_Coordinator->Init();
}

void MenuScene::OnUpdate(float dt)
{
}

void MenuScene::OnRender(sf::RenderWindow& window)
{
}
