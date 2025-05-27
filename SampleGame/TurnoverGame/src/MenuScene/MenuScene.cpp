#include "MenuScene.h"
#include <iostream>



MenuScene::MenuScene() {
	//m_Font.openFromFile("assets/fonts/arial.ttf"); // Error handling skipped

	m_Font = sf::Font("arial.ttf");

	// --- Create Start Button ---
	m_StartButton = CreateEntity("ExitButton");
	auto start_ui_component = new HEngine::UIComponent(sf::RectangleShape({ 200.f, 60.f }), m_Font);
	this->GetComponentRegistry().Add<HEngine::UIComponent>(m_StartButton->GetUUID(), *start_ui_component);
	start_ui_component->shape.setPosition(sf::Vector2f(300.f, 150.f));
	start_ui_component->shape.setFillColor(sf::Color::Blue);

	auto startBox = new HEngine::BoxCollisionComponent(start_ui_component->shape.getGlobalBounds());
	this->GetComponentRegistry().Add<HEngine::BoxCollisionComponent>(m_StartButton->GetUUID(), *startBox);

	// --- Create Exit Button ---
	m_ExitButton = CreateEntity("ExitButton");
	auto exit_ui_component = new HEngine::UIComponent(sf::RectangleShape({ 200.f, 60.f }), m_Font);
	this->GetComponentRegistry().Add<HEngine::UIComponent>(m_ExitButton->GetUUID(), *exit_ui_component);
	exit_ui_component->shape.setPosition(sf::Vector2f(300.f, 300.f));
	exit_ui_component->shape.setFillColor(sf::Color::Blue);

	auto exitBox = new HEngine::BoxCollisionComponent(exit_ui_component->shape.getGlobalBounds());
	this->GetComponentRegistry().Add<HEngine::BoxCollisionComponent>(m_ExitButton->GetUUID(), *exitBox);

}

MenuScene::~MenuScene() {}

void MenuScene::Update(float dt) {
	HandleMouseHover();
	HandleMouseClick();
}

void MenuScene::Render(sf::RenderWindow& window) {
	auto& rc = GetComponentRegistry();

	// Render all entities with RenderComponent
	GetEntityManager().ForEach([&](HEngine::Entity entity) {
			if (rc.Has<HEngine::UIComponent>(entity.GetUUID())) {
				auto render = rc.Get<HEngine::UIComponent>(entity.GetUUID());
				window.draw(render->shape);
			}
		});
}

void MenuScene::HandleMouseHover() {
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	auto highlightIfHovered = [&](HEngine::Entity button) {
			auto& render = *button.GetComponent<HEngine::UIComponent>();
			auto& box = *button.GetComponent<HEngine::BoxCollisionComponent>();

			if (box.Bounds.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
				render.shape.setFillColor(sf::Color::Cyan);
			}
			else {
				render.shape.setFillColor(sf::Color::Blue);
			}
		};

	highlightIfHovered(*m_StartButton);
	highlightIfHovered(*m_ExitButton);
}

void MenuScene::HandleMouseClick() {
	static bool wasPressed = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		if (!wasPressed) {
			wasPressed = true;
			sf::Vector2i mousePos = sf::Mouse::getPosition();

			if ((*m_StartButton->GetComponent<HEngine::BoxCollisionComponent>()).Bounds.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
				std::cout << "Start Game\n";
			}
			else if ((*m_ExitButton->GetComponent<HEngine::BoxCollisionComponent>()).Bounds.contains(sf::Vector2f(mousePos.x, mousePos.y))) {
				std::cout << "Exit Game\n";
			}
		}
	}
	else {
		wasPressed = false;
	}
}
