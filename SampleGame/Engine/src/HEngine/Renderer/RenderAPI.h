#pragma once

#include "HEngine/Core/Core.h"
#include "HEngine/Utils/Color.h"
#include <HEngine/ECS/Component.h>

namespace HEngine {
    class HENGINE_API HRenderAPI {
    public:
        virtual ~HRenderAPI() = default;

        virtual void BeginFrame() = 0;
        virtual void EndFrame() = 0;

        virtual void Clear(HColor color = HColor::Black) = 0;
        virtual void DrawHRect(const RectangleComponent& rect) = 0;
        virtual void DrawHText(const TextComponent& txt) = 0;

        virtual void Present() = 0;
    };
}
