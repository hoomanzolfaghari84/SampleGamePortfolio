#pragma once

#include "RenderAPI.h"
#include "HEngine/ECS/Component.h"

namespace HEngine {

    enum class RenderCommandType {
        DrawHRect,
        DrawHSprite,
        DrawHText,
        // Add more as needed
    };

    struct RenderCommand {
        RenderCommandType type;

        RenderCommand(RenderCommandType type)
            : type(type) {
        }

        virtual ~RenderCommand() = default;
        virtual void Execute(HRenderAPI& renderer) const = 0;
    };

    struct DrawRectCommand : public RenderCommand {
        RectangleComponent rect;

        DrawRectCommand(const RectangleComponent& rect)
            : RenderCommand(RenderCommandType::DrawHRect), rect(rect) {
        }

        void Execute(HRenderAPI& renderer) const override {
            renderer.DrawHRect(rect);
        }
    };

    struct DrawTextCommand : public RenderCommand {
        TextComponent txt;

        DrawTextCommand(const TextComponent& txt)
            : RenderCommand(RenderCommandType::DrawHText), txt(txt) {
            type = RenderCommandType::DrawHText;
        }

        void Execute(HRenderAPI& renderer) const override {
            renderer.DrawHText(txt);
        }
    };

    class HRenderQueue {
    public:
        void Submit(std::unique_ptr<RenderCommand> command) {
            m_Commands.emplace_back(std::move(command));
        }

        void ExecuteAll(HRenderAPI& renderer) {
            for (const auto& cmd : m_Commands)
                cmd->Execute(renderer);
            m_Commands.clear();
        }

    private:
        std::vector<std::unique_ptr<RenderCommand>> m_Commands;
    };
}

