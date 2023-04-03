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

#define BIT(x) (1<<x)
