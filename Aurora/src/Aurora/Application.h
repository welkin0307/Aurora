#pragma once

#pragma once

#include "Core.h"

#include "Window.h"
#include "Aurora/LayerStack.h"
#include "Aurora/Events/Event.h"
#include "Aurora/Events/ApplicationEvent.h"

namespace Aurora {

	class AURORA_API Application
	{
	public:
		//构造函数
		Application();
		//析构函数 接口实际是被Sandbox应用程序继承，故用虚函数
		virtual ~Application();

		void Run();

		// 将回调函数绑定到OnEvent函数上
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window>m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


