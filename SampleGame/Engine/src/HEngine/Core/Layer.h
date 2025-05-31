#pragma once

#include <SFML/Graphics.hpp>

#include "HEngine/Core/Core.h"
#include "HEngine/Core/Timestep.h"
#include "HEngine/Events/HEvent.h"
#include "HEngine/Renderer/RenderAPI.h"

namespace HEngine {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(HTimestep ts) {}
		virtual void OnRender(HRenderAPI& renderer) {}
		virtual void OnEvent(HEvent& event) {}

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}