#pragma once

#include "../Core/UUID.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <functional>
#include "../Utils/HVector2D.h"


#include "../Initializations/Core.h"

namespace HEngine {

	class Entity;

	class HENGINE_API Component {
	public:
		Component() = default;
		virtual ~Component() = default;
		Entity* entity = nullptr;
	};


	class HENGINE_API IDComponent : Component
	{
		UUID ID;

		IDComponent() = default;
		IDComponent(const IDComponent&) = default;
	};

	class HENGINE_API TagComponent : Component
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {
		}
	};

	class HENGINE_API TransformComponent : public Component {
		HVector2Df translation = HVector2Df::Zero;
		float rotation = 0.f; // In degrees
		HVector2Df scale = HVector2Df::One;

		TransformComponent() = default;
		TransformComponent(const HVector2Df& translation)
			: translation(translation) {
		}
	};

	class HENGINE_API UIComponent : public Component {
		
		sf::Text text;
		std::function<void()> onClick;

		bool hovered = false;

	public:
		sf::RectangleShape shape;
		UIComponent(const sf::RectangleShape& shape, sf::Font font = sf::Font("arial.ttf"), const sf::Color& color = sf::Color::White)
			: shape(shape), text(font) {
			this->shape.setFillColor(color);
			SetText("Button Text", font);
		}
		void SetText(const std::string& str, const sf::Font& font, unsigned int size = 30) {
			text.setString(str);
			text.setFont(font);
			text.setCharacterSize(size);
			text.setFillColor(sf::Color::Black);
			text.setPosition(shape.getPosition() + sf::Vector2f(10.f, 10.f)); // Adjust text position
		}
	};


	class HENGINE_API BoxCollisionComponent : public Component {
		
		std::function<void()> onCollision;
	public:
		BoxCollisionComponent() = default;
	    BoxCollisionComponent(const sf::FloatRect& bounds, std::function<void()> onCollision = nullptr)
			: Bounds(bounds), onCollision(onCollision) {
			}
		sf::FloatRect Bounds;
	};

	//struct SpriteRendererComponent : public Component {
	//	sf::Sprite sprite;
	//	sf::Texture texture;

	//	SpriteRendererComponent() = default;

	//	SpriteRendererComponent(const std::string& texturePath) {
	//		if (!texture.loadFromFile(texturePath)) {
	//			// handle error (log it maybe)
	//		}
	//		sprite = sf::Sprite(texture);
	//	}
	//};


	/*struct CameraComponent : public Component {
		sf::View view;

		CameraComponent() = default;
		CameraComponent(const sf::FloatRect& rect)
			: view(rect) {
		}

		void SetCenter(const sf::Vector2f& center) {
			view.setCenter(center);
		}

		void SetSize(const sf::Vector2f& size) {
			view.setSize(size);
		}
	};*/
}