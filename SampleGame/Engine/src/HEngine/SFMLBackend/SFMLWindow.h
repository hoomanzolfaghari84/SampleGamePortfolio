#pragma once

#include "HEngine/Core/Window.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "HEngine/Core/MouseCodes.h"
#include "HEngine/Core/KeyCodes.h"

namespace HEngine {



	constexpr MouseCode ConvertSFMLMouseButtonToHEMouseCode(sf::Mouse::Button button) noexcept
	{
		switch (button)
		{
		case sf::Mouse::Button::Left:     return Mouse::ButtonLeft;
		case sf::Mouse::Button::Right:    return Mouse::ButtonRight;
		case sf::Mouse::Button::Middle:   return Mouse::ButtonMiddle;
		case sf::Mouse::Button::Extra1: return Mouse::Button3;
		case sf::Mouse::Button::Extra2: return Mouse::Button4;
			/*case sf::Mouse::Button0:  return Mouse::Button0;
			case sf::Mouse::Button1:  return Mouse::Button1;
			case sf::Mouse::Button2:  return Mouse::Button2;
			case sf::Mouse::Button3:  return Mouse::Button3;
			case sf::Mouse::Button4:  return Mouse::Button4;
			case sf::Mouse::Button5:  return Mouse::Button5;
			case sf::Mouse::Button6:  return Mouse::Button6;
			case sf::Mouse::Button7:  return Mouse::Button7;*/
		default:                  return static_cast<MouseCode>(-1); // invalid
		}
	}

	constexpr KeyCode ConvertSFMLScancodeToHEKeyCode(sf::Keyboard::Scancode scancode)
	{
		using Sc = sf::Keyboard::Scancode;

		switch (scancode)
		{
		case Sc::A: return Key::A;
		case Sc::B: return Key::B;
		case Sc::C: return Key::C;
		case Sc::D: return Key::D;
		case Sc::E: return Key::E;
		case Sc::F: return Key::F;
		case Sc::G: return Key::G;
		case Sc::H: return Key::H;
		case Sc::I: return Key::I;
		case Sc::J: return Key::J;
		case Sc::K: return Key::K;
		case Sc::L: return Key::L;
		case Sc::M: return Key::M;
		case Sc::N: return Key::N;
		case Sc::O: return Key::O;
		case Sc::P: return Key::P;
		case Sc::Q: return Key::Q;
		case Sc::R: return Key::R;
		case Sc::S: return Key::S;
		case Sc::T: return Key::T;
		case Sc::U: return Key::U;
		case Sc::V: return Key::V;
		case Sc::W: return Key::W;
		case Sc::X: return Key::X;
		case Sc::Y: return Key::Y;
		case Sc::Z: return Key::Z;

		case Sc::Num0: return Key::D0;
		case Sc::Num1: return Key::D1;
		case Sc::Num2: return Key::D2;
		case Sc::Num3: return Key::D3;
		case Sc::Num4: return Key::D4;
		case Sc::Num5: return Key::D5;
		case Sc::Num6: return Key::D6;
		case Sc::Num7: return Key::D7;
		case Sc::Num8: return Key::D8;
		case Sc::Num9: return Key::D9;

		case Sc::Escape: return Key::Escape;
		case Sc::Enter: return Key::Enter;
		case Sc::Tab: return Key::Tab;
		case Sc::Backspace: return Key::Backspace;
		case Sc::Insert: return Key::Insert;
		case Sc::Delete: return Key::Delete;
		case Sc::Right: return Key::Right;
		case Sc::Left: return Key::Left;
		case Sc::Down: return Key::Down;
		case Sc::Up: return Key::Up;
		case Sc::PageUp: return Key::PageUp;
		case Sc::PageDown: return Key::PageDown;
		case Sc::Home: return Key::Home;
		case Sc::End: return Key::End;

		case Sc::CapsLock: return Key::CapsLock;
		case Sc::ScrollLock: return Key::ScrollLock;
		case Sc::NumLock: return Key::NumLock;
		case Sc::PrintScreen: return Key::PrintScreen;
		case Sc::Pause: return Key::Pause;

		case Sc::F1: return Key::F1;
		case Sc::F2: return Key::F2;
		case Sc::F3: return Key::F3;
		case Sc::F4: return Key::F4;
		case Sc::F5: return Key::F5;
		case Sc::F6: return Key::F6;
		case Sc::F7: return Key::F7;
		case Sc::F8: return Key::F8;
		case Sc::F9: return Key::F9;
		case Sc::F10: return Key::F10;
		case Sc::F11: return Key::F11;
		case Sc::F12: return Key::F12;

		case Sc::LShift: return Key::LeftShift;
		case Sc::LControl: return Key::LeftControl;
		case Sc::LAlt: return Key::LeftAlt;
		case Sc::LSystem: return Key::LeftSuper;
		case Sc::RShift: return Key::RightShift;
		case Sc::RControl: return Key::RightControl;
		case Sc::RAlt: return Key::RightAlt;
		case Sc::RSystem: return Key::RightSuper;

		case Sc::Menu: return Key::Menu;

		case Sc::Space: return Key::Space;
		case Sc::Equal: return Key::Equal;
		case Sc::Hyphen: return Key::Minus;
		case Sc::Comma: return Key::Comma;
		case Sc::Period: return Key::Period;
		case Sc::Slash: return Key::Slash;
		case Sc::Semicolon: return Key::Semicolon;
		case Sc::Apostrophe: return Key::Apostrophe;
		case Sc::LBracket: return Key::LeftBracket;
		case Sc::RBracket: return Key::RightBracket;
		case Sc::Backslash: return Key::Backslash;
		case Sc::Grave: return Key::GraveAccent;

		case Sc::Numpad0: return Key::KP0;
		case Sc::Numpad1: return Key::KP1;
		case Sc::Numpad2: return Key::KP2;
		case Sc::Numpad3: return Key::KP3;
		case Sc::Numpad4: return Key::KP4;
		case Sc::Numpad5: return Key::KP5;
		case Sc::Numpad6: return Key::KP6;
		case Sc::Numpad7: return Key::KP7;
		case Sc::Numpad8: return Key::KP8;
		case Sc::Numpad9: return Key::KP9;
		case Sc::NumpadDecimal: return Key::KPDecimal;
		case Sc::NumpadDivide: return Key::KPDivide;
		case Sc::NumpadMultiply: return Key::KPMultiply;
		case Sc::NumpadMinus: return Key::KPSubtract;
		case Sc::NumpadPlus: return Key::KPAdd;
		case Sc::NumpadEnter: return Key::KPEnter;
		case Sc::NumpadEqual: return Key::KPEqual;

		default: return Key::Unknown;
		}
	}

	class SFMLWindow : public Window
	{
	public:
		SFMLWindow(const WindowProps& props);
		virtual ~SFMLWindow();

		void OnUpdate() override;

		uint32_t GetWidth() const override { return m_Data.Width; }
		uint32_t GetHeight() const override { return m_Data.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		void* GetNativeWindow() const override { return m_Window; }

	private:
		void Init(const WindowProps& props);
		void Shutdown();
		void PollEvents();

	private:
		sf::RenderWindow* m_Window = nullptr;
		//std::unique_ptr<> m_Context;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync = true;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;


	};




}



//namespace HEngine {
//
//	class SFMLWindow : public Window
//	{
//	public:
//		SFMLWindow(const WindowProps& props)
//			: m_Window(nullptr), m_Data(props)
//		{
//			Init(props);
//		}
//
//		virtual ~SFMLWindow()
//		{
//			Shutdown();
//		}
//
//		void OnUpdate() override
//		{
//			;
//			while (const std::optional event = m_Window->pollEvent())
//			{
//				// Translate SFML event to HEngine event and call callback
//				HandleEvent(event);
//			}
//
//			m_Window->clear();
//			// Rendering can happen here or externally
//			m_Window->display();
//		}
//
//		uint32_t GetWidth() const override { return m_Data.Width; }
//		uint32_t GetHeight() const override { return m_Data.Height; }
//
//		void SetEventCallback(const EventCallbackFn& callback) override
//		{
//			m_Data.EventCallback = callback;
//		}
//
//		void SetVSync(bool enabled) override
//		{
//			m_Window->setVerticalSyncEnabled(enabled);
//			m_Data.VSync = enabled;
//		}
//
//		bool IsVSync() const override
//		{
//			return m_Data.VSync;
//		}
//
//		void* GetNativeWindow() const override
//		{
//			return m_Window;
//		}
//
//	private:
//		void Init(const WindowProps& props)
//		{
//			sf::ContextSettings settings;
//			settings.depthBits = 24;
//			settings.stencilBits = 8;
//			settings.antiAliasingLevel = 4;
//			settings.majorVersion = 3;
//			settings.minorVersion = 3;
//			m_Window = new sf::RenderWindow(sf::VideoMode({ props.Width, props.Height}), props.Title, sf::Style::Close, sf::State::Windowed, settings);
//			m_Window->setVerticalSyncEnabled(true);
//		}
//
//		void Shutdown()
//		{
//			if (m_Window)
//			{
//				m_Window->close();
//				delete m_Window;
//				m_Window = nullptr;
//			}
//		}
//
//		void HandleEvent(const sf::Event& e)
//		{
//			
//			if (e.is<sf::Event::Closed>())
//			{
//				// HEngine::WindowCloseEvent evt;
//				// m_Data.EventCallback(evt);
//			}
//			// Repeat for other SFML events like KeyPressed, MouseMoved etc.
//		}
//
//	private:
//		sf::RenderWindow* m_Window;
//
//		struct WindowData
//		{
//			std::string Title;
//			uint32_t Width, Height;
//			bool VSync;
//
//			EventCallbackFn EventCallback;
//
//			WindowData(const WindowProps& props)
//				: Title(props.Title), Width(props.Width), Height(props.Height), VSync(true) {
//			}
//		};
//
//		WindowData m_Data;
//	};
//
//}
