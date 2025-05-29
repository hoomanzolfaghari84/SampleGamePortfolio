#pragma once

#include "../Core/UUID.h"
#include <string>
#include <functional>
#include "../Utils/HVector2D.h"


#include "../Initializations/Core.h"
#include "Entity.h"
#include "../Utils/Color.h"

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
	public:
		std::string font_path = "arial.ttf";
		std::string text;
		float x, y, width, height;
		HColor color = HColor::White;

		UIComponent(std::string text, float x, float y, float width, float height);
	};


	class HENGINE_API BoxCollisionComponent : public Component {
	public:
		BoxCollisionComponent() = default;
		BoxCollisionComponent(float x, float y, float width, float height);

		float x = 0.0f, y = 0.0f, width = 1.0f, height = 1.0f;
		std::function<void()> onCollision = nullptr;
	};


}