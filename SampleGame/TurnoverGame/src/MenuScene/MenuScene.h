#pragma once

#include <HEngine.h>

class MenuScene : public HEngine::Scene {
public:
	MenuScene();
	~MenuScene() = default;

	void OnCreate() override;
	void OnUpdate(float dt) override;
	void OnRender(sf::RenderWindow& window) override;


};