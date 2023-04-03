#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Aurora {

	class AURORA_API Application
	{
	public:
		//���캯��
		Application();
		//�������� �ӿ�ʵ���Ǳ�SandboxӦ�ó���̳У������麯��
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window>m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


