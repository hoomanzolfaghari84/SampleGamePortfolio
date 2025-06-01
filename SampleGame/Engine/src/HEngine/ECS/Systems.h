#pragma once

#include "HECS.hpp";

namespace HEngine {
	class RectangleRenderSystem : public ECS::System {
		void Update(const HEngine::ECS::SystemContext& ctx) {
			for (auto entity : entities) {
				if (ctx.coordinator.HasComponent<RectangleComponent>(entity)) {
					auto& rect_c = ctx.coordinator.GetComponent<RectangleComponent>(entity);
					ctx.renderQueue.Submit(std::make_unique<DrawRectCommand>(rect_c));
				}
			}
		}
	};

    //class UIButtonSystem : public ECS::System {
    //public:
    //    void Update(const HEngine::ECS::SystemContext& ctx) override {
    //        for (auto entity : entities) {
    //            auto& button = ctx.coordinator.GetComponent<UIButtonComponent>(entity);
    //            auto& transform = ctx.coordinator.GetComponent<UITransformComponent>(entity);

    //            // Mouse input (assume GetMousePosition returns HVector2Di)
    //            auto mousePos = HInput::GetMousePosition();

    //            bool hovering = mousePos.x >= transform.position.x &&
    //                mousePos.x <= transform.position.x + transform.size.x &&
    //                mousePos.y >= transform.position.y &&
    //                mousePos.y <= transform.position.y + transform.size.y;

    //            if (hovering && !button.hovered) {
    //                button.hovered = true;
    //                // Optional: play hover sound or visual
    //            }
    //            else if (!hovering && button.hovered) {
    //                button.hovered = false;
    //            }

    //            if (hovering && HInput::IsMouseButtonPressed(HEngine::Mouse::ButtonLeft)) {
    //                if (button.onClick)
    //                    button.onClick();  // Call the callback
    //            }
    //        }
    //    }
    //};

    //class UISystem : public HEngine::System {
    //public:
    //    void Update(const HEngine::SystemContext& ctx) override {
    //        for (auto entity : entities) {
    //            const auto& transform = ctx.coordinator.GetComponent<UITransformComponent>(entity);
    //            const auto& uiRender = ctx.coordinator.GetComponent<UIRenderComponent>(entity);

    //            HEngine::HDrawable2D drawCmd;
    //            drawCmd.position = transform.position;
    //            drawCmd.size = transform.size;
    //            drawCmd.texture = uiRender.texture;
    //            drawCmd.tint = uiRender.tint;

    //            ctx.renderQueue.Push(drawCmd);
    //        }
    //    }
    //};

    //class AnimatedSpriteSystem : public HEngine::System {
    //public:
    //    void Update(const HEngine::SystemContext& ctx) override {
    //        for (auto entity : entities) {
    //            auto& anim = ctx.coordinator.GetComponent<AnimatedSpriteComponent>(entity);

    //            anim.elapsed += ctx.ts.GetSeconds();

    //            if (anim.elapsed >= anim.frameTime) {
    //                anim.elapsed = 0.0f;
    //                anim.currentFrame = (anim.currentFrame + 1) % anim.totalFrames;
    //            }

    //            if (ctx.coordinator.HasComponent<UIRenderComponent>(entity)) {
    //                auto& render = ctx.coordinator.GetComponent<UIRenderComponent>(entity);
    //                render.texture = anim.frames[anim.currentFrame]; // Replace texture with current frame
    //            }
    //        }
    //    }
    //};


}

