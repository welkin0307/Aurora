#include "aurpch.h"
#include "Aurora/Core/Window.h"

#ifdef AUR_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Aurora
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef AUR_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		AUR_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}