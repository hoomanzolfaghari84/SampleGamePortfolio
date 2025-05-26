#include "Application.h"
#include <iostream>

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
			std::cout << "Running application... " << i << std::endl;
			i--;
		}
	}
}