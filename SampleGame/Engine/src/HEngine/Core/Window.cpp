#include "hepch.h"
#include "Window.h"


#ifdef HE_PLATFORM_WINDOWS
#include "HEngine/SFMLBackend/SFMLWindow.h"
#endif

namespace HEngine
{
	std::unique_ptr<Window> Window::Create(const WindowProps& props)
	{
#ifdef HE_PLATFORM_WINDOWS
		return std::make_unique<SFMLWindow>(props);
#else
        #error HEngine Currently only supports windows!
		return nullptr;
#endif
	}

}