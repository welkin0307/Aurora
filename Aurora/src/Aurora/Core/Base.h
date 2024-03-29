#pragma once

#include <memory>

#include "Aurora/Core/PlatformDetection.h"


// ����
#ifdef AUR_DEBUG
#if defined(AUR_PLATFORM_WINDOWS)
#define AUR_DEBUGBREAK() __debugbreak()
#elif defined(AUR_PLATFORM_LINUX)
#include <signal.h>
#define AUR_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define AUR_ENABLE_ASSERTS
#else
#define AUR_DEBUGBREAK()
#endif


#define AUR_EXPAND_MACRO(x) x
#define AUR_STRINGIFY_MACRO(x) #x

// λ���� 1 << x = 1*2^x
#define BIT(x) (1 << x)

#define AUR_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Aurora {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Aurora/Core/Log.h"
#include "Aurora/Core/Assert.h"
