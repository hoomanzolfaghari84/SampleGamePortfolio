#pragma once

#include "HEngine/Core/UUID.h"
#include "HEngine/Utils/Color.h"
#include "HEngine/Utils/HVector2D.h"

namespace HEngine {

    enum class BodyType
    {
        Static = 0,
        Dynamic,
        Kinematic
    };
	
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

    struct HENGINE_API ButtonComponent {
        RectangleComponent Rectangle;
        TextComponent Text;

    };

    struct HENGINE_API SpriteComponent
    {
        std::string texturePath;
        int zIndex = 0; // For rendering order

        SpriteComponent() = default;
        SpriteComponent(const std::string& path, int z = 0)
            : texturePath(path), zIndex(z) {
        }
    };

    struct HENGINE_API CameraComponent
    {
        bool primary = true;
        float zoom = 1.0f;

        CameraComponent() = default;
        explicit CameraComponent(bool isPrimary, float z = 1.0f)
            : primary(isPrimary), zoom(z) {
        }
    };

    struct HENGINE_API ColliderComponent
    {
        HVector2Df size{ 1.0f, 1.0f };
        bool isTrigger = false;

        ColliderComponent() = default;
        explicit ColliderComponent(const HVector2Df& sz, bool trigger = false)
            : size(sz), isTrigger(trigger) {
        }
    };

   

    struct HENGINE_API RigidBodyComponent
    {
        BodyType type = BodyType::Static;
        bool useGravity = true;

        RigidBodyComponent() = default;
        RigidBodyComponent(BodyType t, bool gravity = true)
            : type(t), useGravity(gravity) {
        }
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


    // ## UI Components ##
    enum class UIAnchor
    {
        TopLeft,
        TopCenter,
        TopRight,
        MiddleLeft,
        MiddleCenter,
        MiddleRight,
        BottomLeft,
        BottomCenter,
        BottomRight
    };

    struct UITransformComponent
    {
        HVector2Df size{ 100.0f, 50.0f };          // in pixels
        HVector2Df offset{ 0.0f, 0.0f };           // pixel offset from anchor
        UIAnchor anchor = UIAnchor::TopLeft;      // where it is anchored
        HVector2Df pivot{ 0.5f, 0.5f };            // normalized pivot (0 to 1)

        UITransformComponent() = default;
    };

    struct UITextComponent
    {
        std::string text;
        std::string fontPath;
        unsigned int fontSize = 16;
        uint32_t color = 0xFFFFFFFF; // RGBA as hex

        UITextComponent() = default;
        UITextComponent(const std::string& txt, const std::string& font, unsigned int size)
            : text(txt), fontPath(font), fontSize(size) {
        }
    };

    struct UIButtonComponent
    {
        bool hovered = false;
        bool pressed = false;
        bool interactable = true;

        // You can store event callback IDs or function pointers if needed
        std::function<void()> onClick;

        UIButtonComponent() = default;
    };

    struct UIImageComponent
    {
        std::string texturePath;
        uint32_t tint = 0xFFFFFFFF; // RGBA
        bool visible = true;

        UIImageComponent() = default;
    };

    // ## Animation Compontets ##

    struct SpriteFrame
    {
        std::string texturePath;
        float duration = 0.1f; // seconds
    };

    struct AnimatedSpriteComponent
    {
        std::vector<SpriteFrame> frames;
        float elapsed = 0.0f;
        size_t currentFrame = 0;
        bool looping = true;
        bool playing = true;

        AnimatedSpriteComponent() = default;

        void AddFrame(const std::string& path, float duration)
        {
            frames.push_back({ path, duration });
        }

        void Reset()
        {
            elapsed = 0.0f;
            currentFrame = 0;
        }
    };
}
