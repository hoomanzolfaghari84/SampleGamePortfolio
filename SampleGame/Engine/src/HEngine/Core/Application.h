#pragma once

#include "GameEngine.h"

namespace HEngine {

	class HENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void AddScene(std::shared_ptr<HEngine::Scene> scene);

	private:
		std::unique_ptr<GameEngine> engine;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

