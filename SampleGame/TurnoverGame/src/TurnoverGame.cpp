#include <HEngine.h>
#include "HEngine/Initializations/EntryPoint.h"

class TurnoverGame : public HEngine::Application
{

public:
	TurnoverGame()
	{
	}

	~TurnoverGame()
	{
	}
};


HEngine::Application* HEngine::CreateApplication()
{
	return new TurnoverGame();
}
