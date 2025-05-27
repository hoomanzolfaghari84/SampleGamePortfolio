#pragma once

#include <HEngine.h>

class MenuScene : public HEngine::Scene {
public:
	MenuScene();
	~MenuScene();

	void Update(float dt) override;
	void Render(sf::RenderWindow& window) override;

private:
	sf::Font m_Font;
	HEngine::Entity* m_StartButton;
	HEngine::Entity* m_ExitButton;

	void HandleMouseHover();
	void HandleMouseClick();
};