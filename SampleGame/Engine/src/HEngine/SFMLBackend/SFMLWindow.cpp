#include "hepch.h"
#include "SFMLWindow.h"

#include "HEngine/Events/ApplicationEvent.h"
#include "HEngine/Events/KeyEvent.h"
#include "HEngine/Events/MouseEvent.h"

#include "HEngine/Renderer/RenderAPI.h"

namespace HEngine {

	SFMLWindow::SFMLWindow(const WindowProps& props)
	{
		Init(props);
	}

	SFMLWindow::~SFMLWindow()
	{
		Shutdown();
	}

	void SFMLWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HE_CORE_INFO("Creating SFML window: {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		m_Window = new sf::RenderWindow(sf::VideoMode({ m_Data.Width, m_Data.Height }), m_Data.Title);
		m_Window->setVerticalSyncEnabled(true); // Default VSync on
	}

	void SFMLWindow::Shutdown()
	{
		if (m_Window)
		{
			m_Window->close();
			delete m_Window;
			m_Window = nullptr;
		}
	}

	void SFMLWindow::OnUpdate()
	{
		PollEvents();
		m_Window->clear();
		// The user is expected to draw here
		m_Window->display();
	}

	void SFMLWindow::SetVSync(bool enabled)
	{
		m_Window->setVerticalSyncEnabled(enabled);
		m_Data.VSync = enabled;
	}

	bool SFMLWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void SFMLWindow::PollEvents()
	{
		
		while (const std::optional event = m_Window->pollEvent())
		{
	
			if (event->is<sf::Event::Closed>())
			{
				WindowCloseEvent e;
				m_Data.EventCallback(e);
			
			}
			else if (const auto resized = event->getIf<sf::Event::Resized>())
			{	
				WindowResizeEvent e(resized->size.x, resized->size.y);
				m_Data.Width = resized->size.x;
				m_Data.Height = resized->size.y;
				m_Data.EventCallback(e);
				
			}
			/*else if (const auto lostFocus = event->getIf<sf::Event::FocusLost>()) {
				WindowLostFocusEvent e;
				m_Data.EventCallback(e);
				break;
			}*/
			else if (const auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				KeyPressedEvent e(ConvertSFMLScancodeToHEKeyCode(keyPressed->scancode));
				m_Data.EventCallback(e);
				break;
			}
			else if (const auto keyReleased = event->getIf<sf::Event::KeyReleased>()) {
				KeyReleasedEvent e(ConvertSFMLScancodeToHEKeyCode(keyReleased->scancode));
				m_Data.EventCallback(e);
				break;
			}
			else if (const auto textEntered = event->getIf<sf::Event::TextEntered>()) {
				
				KeyTypedEvent e(textEntered->unicode); //Check validity
				m_Data.EventCallback(e);
				break;
				
			}
			else if (const auto sfe = event->getIf<sf::Event::MouseButtonPressed>()) {

				MouseButtonPressedEvent e(ConvertSFMLMouseButtonToHEMouseCode(sfe->button));
				m_Data.EventCallback(e);
				break;
			}
			else if (const auto sfe = event->getIf<sf::Event::MouseButtonReleased>()) {

				MouseButtonReleasedEvent e(ConvertSFMLMouseButtonToHEMouseCode(sfe->button));
				m_Data.EventCallback(e);
				break;
			}
			else if (const auto sfe = event->getIf<sf::Event::MouseMoved>()) {

				MouseMovedEvent e(sfe->position.x, sfe->position.y);
				m_Data.EventCallback(e);
				break;
			}
			/*else if (const auto sfe = event->getIf<sf::Event::MouseWheelScrolled>()) {

				MouseScrolledEvent e(sfe->position.x, sfe->position.y);
				m_Data.EventCallback(e);
				break;
			}*/


			/*
			case sf::Event::GainedFocus:
			{
				WindowFocusEvent e;
				m_Data.EventCallback(e);
				break;
			}
			
			case sf::Event::MouseWheelScrolled:
			{
				MouseScrolledEvent e((float)event.mouseWheelScroll.delta, 0.0f);
				m_Data.EventCallback(e);
				break;
			}
			}*/
		}
	}


}
