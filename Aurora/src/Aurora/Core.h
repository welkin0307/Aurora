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

// λ���� 1 << x = 1*2^x
#define BIT(x) (1 << x)
