#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Aurora {

	class AURORA_API Application
	{
	public:
		//���캯��
		Application();
		//�������� �ӿ�ʵ���Ǳ�SandboxӦ�ó���̳У������麯��
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


