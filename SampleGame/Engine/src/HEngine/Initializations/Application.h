#pragma once

#include "Core.h"
#include "..\Core\GameEngine.h"

namespace HEngine {

	class HENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void SetCurrentScene(std::unique_ptr<HEngine::Scene> scene);

	private:
		std::unique_ptr<GameEngine> engine;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

