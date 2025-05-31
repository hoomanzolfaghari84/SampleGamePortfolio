#include "hepch.h"
#include "Application.h"

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
		engine->Init();
		engine->Run();
		engine->Shutdown();
	}

	void Application::AddScene(std::shared_ptr<HEngine::Scene> scene) {
		this->engine->AddScene(std::move(scene));
	}
}