#pragma once

#include "HEngine/Core/UUID.h"
#include "HEngine/Utils/Color.h"
#include "HEngine/Utils/HVector2D.h"

namespace HEngine {
	
    struct HENGINE_API IDComponent {
        UUID ID;
    };

    struct HENGINE_API TagComponent {
        std::string Tag;

        TagComponent() = default;
        TagComponent(const std::string& tag) : Tag(tag) {}
    };

    struct HENGINE_API Transform2DComponent {
        HVector2Df translation = HVector2Df::Zero();
        float rotation = 0.f;
        HVector2Df scale = HVector2Df::One();
    };

    struct HENGINE_API Kinematics2DComponent {
        HVector2Df position = HVector2Df::Zero();
        HVector2Df velocity = HVector2Df::Zero();
        HVector2Df acceleration = HVector2Df::Zero();
    };
    
    struct HENGINE_API RectangleComponent {
        HVector2Df position = HVector2Df::Zero();
        HVector2Df size = HVector2Df::One();
		HColor color = HColor::White;
    };

    struct HENGINE_API CircleComponent {
        HVector2Df position = HVector2Df::Zero();
        float radius = 50.f;
        HColor color = HColor::White;
	};

    struct HENGINE_API TextComponent {
		HVector2Df position = HVector2Df::Zero();
        std::string text;
        HColor color = HColor::White;
        unsigned int character_size = 16.f;
        std::string fontPath; // Path to the font file
	};

}
