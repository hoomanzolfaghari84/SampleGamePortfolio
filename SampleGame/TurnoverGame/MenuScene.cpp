#include "MenuScene.h"
#include <iostream>



MenuScene::MenuScene() {
	//m_Font.openFromFile("assets/fonts/arial.ttf"); // Error handling skipped

	//sf::Font m_font("arial.ttf");

	//// --- Create Start Button ---
	//m_StartButton = CreateEntity("StartButton");
	//auto& start_ui_component = m_StartButton->AddComponent<HEngine::UIComponent>();
	//start_ui_component.shape = sf::RectangleShape({ 200.f, 60.f });
	//start_ui_component.shape.setPosition(sf::Vector2f(300.f, 200.f));
	//start_ui_component.shape.setFillColor(sf::Color::Blue);

	//auto& startBox = m_StartButton->AddComponent<HEngine::BoxCollisionComponent>();
	//startBox.Bounds = start_ui_component.shape.getGlobalBounds();

	//// --- Create Exit Button ---
	//m_ExitButton = CreateEntity("ExitButton");
	//auto& exit_ui_component = m_StartButton->AddComponent<HEngine::UIComponent>();
	//exit_ui_component.shape = sf::RectangleShape({ 200.f, 60.f });
	//exit_ui_component.shape.setPosition(sf::Vector2f(300.f, 300.f));
	//exit_ui_component.shape.setFillColor(sf::Color::Blue);

	//auto& exitBox = m_ExitButton->AddComponent<HEngine::BoxCollisionComponent>();
	//exitBox.Bounds = exit_ui_component.shape.getGlobalBounds();

}

MenuScene::~MenuScene() {}

void MenuScene::Update(float dt) {
	HandleMouseHover();
	HandleMouseClick();
}

void MenuScene::Render(sf::RenderWindow& window) {
	//auto& rc = GetComponentRegistry();

	//// Render all entities with RenderComponent
	//GetEntityManager().ForEach([&](HEngine::Entity entity) {
	//		if (rc.Has<HEngine::UIComponent>(entity.GetUUID())) {
	//			auto render = rc.Get<HEngine::UIComponent>(entity.GetUUID());
	//			window.draw(render->shape);
	//		}
	//	});
}

void MenuScene::HandleMouseHover() {
	/*sf::Vector2i mousePos = sf::Mouse::getPosition();

	auto highlightIfHovered = [&](Entity* button) {
		auto& render = button->GetComponent<RenderComponent>();
		auto& box = button->GetComponent<CollisionBoxComponent>();

		if (box.Bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
			render.Shape.setFillColor(sf::Color::Cyan);
		}
		else {
			render.Shape.setFillColor(sf::Color::Blue);
		}
		};

	highlightIfHovered(m_StartButton);
	highlightIfHovered(m_ExitButton);*/
}

void MenuScene::HandleMouseClick() {
	/*static bool wasPressed = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!wasPressed) {
			wasPressed = true;
			sf::Vector2i mousePos = sf::Mouse::getPosition();

			if (m_StartButton->GetComponent<CollisionBoxComponent>().Bounds.contains(mousePos.x, mousePos.y)) {
				std::cout << "Start Game\n";
			}
			else if (m_ExitButton->GetComponent<CollisionBoxComponent>().Bounds.contains(mousePos.x, mousePos.y)) {
				std::cout << "Exit Game\n";
			}
		}
	}
	else {
		wasPressed = false;
	}*/
}
