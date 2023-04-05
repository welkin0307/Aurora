#pragma once

//ͨ����������.dll�ļ��Ĺ��������ӣ���ǰֻ֧��Windowsƽ̨��
#ifdef AUR_PLATFORM_WINDOWS
	
	#ifdef AUR_BUILD_DLL
		//����㹹��
		#define AURORA_API __declspec(dllexport)
	#else
		//�ⲿӦ�ò�����
		#define AURORA_API __declspec(dllimport)
	#endif // AUR_BUILD_DLL

#else
	//��Windowsƽ̨��������
	#error Aurora Engine only supports Windows!

#endif

// ����
#ifdef AUR_ENABLE_ASSERTS
	#define AUR_CLIENT_ASSERT(x,...){ if(!(x)){AUR_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
	#define AUR_CORE_ASSERT(x,...) {if(!(x)){AUR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
	#define AUR_CLIENT_ASSERT(x,...)
	#define AUR_CORE_ASSERT(x,...)
#endif

// λ���� 1 << x = 1*2^x
#define BIT(x) (1 << x)

#define AUR_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)
