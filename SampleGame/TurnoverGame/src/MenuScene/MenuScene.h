#pragma once

#include <HEngine.h>


class MenuScene : public HEngine::Scene {
public:
    MenuScene() : HEngine::Scene("MenuScene") {
        OnCreate();
    }

    void OnCreate() override {

        /*CreateTitle();
        CreatePlayButton();
        CreateQuitButton();
        CreateSideAnimation();*/

        m_Coordinator->Init();
        //m_Coordinator.RegisterComponent<HEngine::Transform2DComponent>();
        m_Coordinator->RegisterComponent<HEngine::RectangleComponent>();
        m_Coordinator->RegisterSystem<HEngine::RectangleRenderSystem>();

        // Start Button
        auto startBtn = m_Coordinator->CreateEntity();
        auto rect_c = HEngine::RectangleComponent();
        rect_c.position = { 300.0f, 150.0f };
        rect_c.color = HEngine::HColor::Green;
        rect_c.size = { 150.0f, 100.0f };
        m_Coordinator->AddComponent(startBtn, rect_c);

        // Exit Button
        auto exitBtn = m_Coordinator->CreateEntity();
        auto rect_ce = HEngine::RectangleComponent();
        rect_ce.position = { 300.0f, 300.0f };
        rect_ce.color = HEngine::HColor::Blue;
        rect_ce.size = { 150.0f, 100.0f };
        m_Coordinator->AddComponent(exitBtn, rect_ce);

    }
private:
	//void CreateTitle()
	//{
	//	Entity title = CreateEntity("Title");
	//	auto& transform = AddComponent<UITransformComponent>(title);
	//	transform.anchor = UIAnchor::TopCenter;
	//	transform.offset = HVector2Df(0.0f, 50.0f);

	//	auto& text = AddComponent<UITextComponent>(title);
	//	text.text = "My Cool Game";
	//	text.fontPath = "assets/fonts/Roboto-Bold.ttf";
	//	text.fontSize = 36;
	//}

	//void CreatePlayButton()
	//{
	//	Entity playBtn = CreateEntity("PlayButton");

	//	auto& transform = AddComponent<UITransformComponent>(playBtn);
	//	transform.anchor = UIAnchor::MiddleCenter;
	//	transform.offset = HVector2Df(0.0f, -40.0f);
	//	transform.size = HVector2Df(200.0f, 50.0f);

	//	AddComponent<UIImageComponent>(playBtn).texturePath = "assets/ui/button.png";

	//	auto& button = AddComponent<UIButtonComponent>(playBtn);
	//	button.onClick = []() {
	//		std::cout << "[Play Button] Clicked!" << std::endl;
	//		// Transition to game scene here
	//		};

	//	auto& text = AddComponent<UITextComponent>(playBtn);
	//	text.text = "Play";
	//	text.fontPath = "assets/fonts/Roboto-Regular.ttf";
	//	text.fontSize = 24;
	//}

	//void CreateQuitButton()
	//{
	//	Entity quitBtn = CreateEntity("QuitButton");

	//	auto& transform = AddComponent<UITransformComponent>(quitBtn);
	//	transform.anchor = UIAnchor::MiddleCenter;
	//	transform.offset = HVector2Df(0.0f, 40.0f);
	//	transform.size = HVector2Df(200.0f, 50.0f);

	//	AddComponent<UIImageComponent>(quitBtn).texturePath = "assets/ui/button.png";

	//	auto& button = AddComponent<UIButtonComponent>(quitBtn);
	//	button.onClick = []() {
	//		std::cout << "[Quit Button] Clicked!" << std::endl;
	//		// Exit application here
	//		};

	//	auto& text = AddComponent<UITextComponent>(quitBtn);
	//	text.text = "Quit";
	//	text.fontPath = "assets/fonts/Roboto-Regular.ttf";
	//	text.fontSize = 24;
	//}

	//void CreateSideAnimation()
	//{
	//	Entity anim = CreateEntity("SideAnimation");

	//	auto& transform = AddComponent<UITransformComponent>(anim);
	//	transform.anchor = UIAnchor::MiddleRight;
	//	transform.offset = HVector2Df(-100.0f, 0.0f);
	//	transform.size = HVector2Df(128.0f, 128.0f);

	//	auto& animSprite = AddComponent<AnimatedSpriteComponent>(anim);
	//	animSprite.AddFrame("assets/sprites/idle1.png", 0.2f);
	//	animSprite.AddFrame("assets/sprites/idle2.png", 0.2f);
	//	animSprite.AddFrame("assets/sprites/idle3.png", 0.2f);
	//	animSprite.looping = true;
	//	animSprite.playing = true;
	//}
    //void OnUpdate(HEngine::HTimestep ts) override {
    //    // Add animation or hover detection if needed
    //}

    /*void OnRender(HEngine::HRenderAPI& renderer) override {
        
    }*/


};