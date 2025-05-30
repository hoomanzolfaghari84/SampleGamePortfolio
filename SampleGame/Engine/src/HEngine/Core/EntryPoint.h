#pragma once
#include "Application.h"
#include "HEngine/Utils/Logger.h"

#ifdef HE_PLATFORM_WINDOWS

extern HEngine::Application* HEngine::CreateApplication();

int main(int argc, char** argv)
{
	HEngine::HLogger::Init();
	HE_CORE_WARN("Initialized Log!");
	int a = 5;
	HE_CORE_INFO("Created App");
	auto app = HEngine::CreateApplication();
	HE_CORE_INFO("Created App");
	app->Run();
	HE_CORE_INFO("Exited App Run");
	delete app;
}

#endif // HE_PLATFORM_WINDOWS
