#pragma once

#include <memory>

//通过宏来控制.dll文件的构建和链接（当前只支持Windows平台）
// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
#ifdef _WIN64
	/* Windows x64  */
#define AUR_PLATFORM_WINDOWS
#else
	/* Windows x86 */
#error "x86 Builds are not supported!"
#endif
#elif defined(__APPLE__) || defined(__MACH__)
#include <TargetConditionals.h>
/* TARGET_OS_MAC exists on all the platforms
 * so we must check all of them (in this order)
 * to ensure that we're running on MAC
 * and not some other Apple platform */
#if TARGET_IPHONE_SIMULATOR == 1
#error "IOS simulator is not supported!"
#elif TARGET_OS_IPHONE == 1
#define AUR_PLATFORM_IOS
#error "IOS is not supported!"
#elif TARGET_OS_MAC == 1
#define AUR_PLATFORM_MACOS
#error "MacOS is not supported!"
#else
#error "Unknown Apple platform!"
#endif
 /* We also have to check __ANDROID__ before __linux__
  * since android is based on the linux kernel
  * it has __linux__ defined */
#elif defined(__ANDROID__)
#define AUR_PLATFORM_ANDROID
#error "Android is not supported!"
#elif defined(__linux__)
#define AUR_PLATFORM_LINUX
#error "Linux is not supported!"
#else
	/* Unknown compiler/platform */
#error "Unknown platform!"
#endif // End of platform detection


// DLL support


#ifdef AUR_PLATFORM_WINDOWS
	#if AUR_DYNAMIC_LINK
		#ifdef AUR_BUILD_DLL
			//引擎层构建
			#define AURORA_API __declspec(dllexport)
		#else
			//外部应用层链接
			#define AURORA_API __declspec(dllimport)
		#endif // AUR_BUILD_DLL

	#else
		#define AURORA_API
	#endif
#else
	//非Windows平台构建报错
	#error Aurora Engine only supports Windows!
#endif

// 调试
#ifdef AUR_DEBUG
	#define AUR_ENABLE_ASSERTS
#endif // AUR_DEBUG


// 断言
#ifdef AUR_ENABLE_ASSERTS
	#define AUR_CLIENT_ASSERT(x,...){ if(!(x)){AUR_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
	#define AUR_CORE_ASSERT(x,...) {if(!(x)){AUR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
	#define AUR_CLIENT_ASSERT(x,...)
	#define AUR_CORE_ASSERT(x,...)
#endif

// 位运算 1 << x = 1*2^x
#define BIT(x) (1 << x)

#define AUR_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)

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