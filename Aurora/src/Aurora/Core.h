#pragma once

//通过宏来控制.dll文件的构建和链接（当前只支持Windows平台）
#ifdef AUR_PLATFORM_WINDOWS
	
	#ifdef AUR_BUILD_DLL
		//引擎层构建
		#define AURORA_API __declspec(dllexport)
	#else
		//外部应用层链接
		#define AURORA_API __declspec(dllimport)
	#endif // AUR_BUILD_DLL

#else
	//非Windows平台构建报错
	#error Aurora Engine only supports Windows!

#endif

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
