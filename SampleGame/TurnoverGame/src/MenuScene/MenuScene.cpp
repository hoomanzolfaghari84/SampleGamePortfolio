#include "MenuScene.h"
#include <iostream>



MenuScene::MenuScene() {
	
	HE_INFO("Creating Start Button");
	// --- Create Start Button ---
	m_StartButton = CreateEntity("StartButton");
	//std::string s_text = "start"; //std::string("Start");
	auto start_ui_component = HEngine::UIComponent("Start", 300.f, 150.f, 200.f, 60.f);
	start_ui_component.color = HColor::Green;
	this->GetComponentRegistry().Add<HEngine::UIComponent>(m_StartButton->GetUUID(), start_ui_component);
	
	auto startBox = HEngine::BoxCollisionComponent(300.f, 150.f, 200.f, 60.f);
	this->GetComponentRegistry().Add<HEngine::BoxCollisionComponent>(m_StartButton->GetUUID(), startBox);

	HE_INFO("Creating Exit Button");
	// --- Create Exit Button ---
	m_ExitButton = CreateEntity("ExitButton");
	//std::string&& e_text = std::string("Exit");
	auto exit_ui_component = HEngine::UIComponent("Exit", 300.f, 300.f, 200.f, 60.f);
	exit_ui_component.color = HColor::Blue;
	this->GetComponentRegistry().Add<HEngine::UIComponent>(m_ExitButton->GetUUID(), exit_ui_component);

	auto exitBox = HEngine::BoxCollisionComponent(300.f, 300.f, 200.f, 60.f);
	this->GetComponentRegistry().Add<HEngine::BoxCollisionComponent>(m_ExitButton->GetUUID(), exitBox);

}

MenuScene::~MenuScene() {}

void MenuScene::Update(float dt) {
	HandleMouseHover();
	HandleMouseClick();
}

void MenuScene::Render(sf::RenderWindow& window) {
	
}

void MenuScene::HandleMouseHover() {
	//sf::Vector2i mousePos = sf::Mouse::getPosition();

	//auto highlightIfHovered = [&](HEngine::Entity button) {
	//	auto& render = *this->GetComponentRegistry().Get<HEngine::UIComponent>(button.GetUUID());// *button.GetComponent<HEngine::UIComponent>();
	//		auto& box = *this->GetComponentRegistry().Get<HEngine::BoxCollisionComponent>(button.GetUUID());

	//		if (box.Bounds.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
	//			render.shape.setFillColor(sf::Color::Cyan);
	//		}
	//		/*else {
	//			render.shape.setFillColor(sf::Color::Blue);
	//		}*/
	//	};

	//highlightIfHovered(*m_StartButton);
	//highlightIfHovered(*m_ExitButton);
}

void MenuScene::HandleMouseClick() {
	/*static bool wasPressed = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		if (!wasPressed) {
			wasPressed = true;
			sf::Vector2i mousePos = sf::Mouse::getPosition();

			if ((*this->GetComponentRegistry().Get<HEngine::BoxCollisionComponent>(m_StartButton->GetUUID())).Bounds.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
				std::cout << "Start Game\n";
			}
			else if ((*this->GetComponentRegistry().Get<HEngine::BoxCollisionComponent>(m_ExitButton->GetUUID())).Bounds.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
				std::cout << "Exit Game\n";
			}
		}
	}
	else {
		wasPressed = false;
	}*/
}
