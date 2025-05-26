#include <HEngine.h>

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