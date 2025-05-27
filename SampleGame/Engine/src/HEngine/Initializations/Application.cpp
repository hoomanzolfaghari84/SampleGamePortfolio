#include "Application.h"
#include <iostream>
#include "../Utils/Logger.h"

namespace HEngine{
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		int i = 5;
		while (i>0)
		{
			// Main loop logic goes here
			HE_INFO("Application is running. Remaining iterations: {}", i);
			i--;
		}
	}
}