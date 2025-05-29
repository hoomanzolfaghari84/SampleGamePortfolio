#include <HEngine.h>
#include "HEngine/Initializations/EntryPoint.h"
#include "MenuScene/MenuScene.h"

class TurnoverGame : public HEngine::Application
{

public:
	TurnoverGame()
	{
		SetCurrentScene(std::make_unique<MenuScene>());
	}

	~TurnoverGame()
	{
	}
};


HEngine::Application* HEngine::CreateApplication()
{
	return new TurnoverGame();
}
