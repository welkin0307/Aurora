#include "aurpch.h"
#include "Aurora/Core/Input.h"

#ifdef AUR_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace Aurora {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef AUR_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		AUR_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}