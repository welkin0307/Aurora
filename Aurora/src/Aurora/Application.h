#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Aurora {

	class AURORA_API Application
	{
	public:
		//构造函数
		Application();
		//析构函数 接口实际是被Sandbox应用程序继承，故用虚函数
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window>m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


