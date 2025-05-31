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

}

