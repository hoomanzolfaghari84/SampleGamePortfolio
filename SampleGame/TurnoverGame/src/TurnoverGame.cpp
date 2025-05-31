#include <HEngine.h>
#include "HEngine/Core/EntryPoint.h"
#include "MenuScene/MenuScene.h"


class TurnoverGame : public HEngine::Application
{

public:
	TurnoverGame()
	{
		AddScene(std::make_shared<MenuScene>());
	}

	~TurnoverGame()
	{
	}
};


HEngine::Application* HEngine::CreateApplication()
{
	return new TurnoverGame();
}
