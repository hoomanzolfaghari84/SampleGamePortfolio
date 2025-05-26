#pragma once

#include "../Core/UUID.h"
#include <string>
#include "../../../HVector2D.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include "../Utils/HVector2D.h"

namespace HEngine {

	class Entity;

	class Component {
	public:
		virtual ~Component() = default;
		Entity* entity = nullptr;
	};


	struct IDComponent : Component
	{
		UUID ID;

		IDComponent() = default;
		IDComponent(const IDComponent&) = default;
	};

	struct TagComponent : Component
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {
		}
	};

	struct TransformComponent : public Component {
		HVector2Df translation = HVector2Df::Zero;
		float rotation = 0.f; // In degrees
		HVector2Df scale = HVector2Df::One;

		TransformComponent() = default;
		TransformComponent(const HVector2Df& translation)
			: translation(translation) {
		}
	};

	struct UIComponent : public Component {
		sf::RectangleShape shape;
		sf::Text text;
		std::function<void()> onClick;

		bool hovered = false;
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