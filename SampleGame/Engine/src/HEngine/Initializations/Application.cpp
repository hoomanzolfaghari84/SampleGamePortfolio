#include "Application.h"
#include <iostream>
#include "../Utils/Logger.h"

namespace HEngine{
	Application::Application()
	{
		engine = std::make_unique<GameEngine>();
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		HE_INFO("Application running started");
		engine->Run();
	}

	void Application::SetCurrentScene(std::unique_ptr<HEngine::Scene> scene) {
		this->engine->ChangeScene(std::move(scene));
	}
}