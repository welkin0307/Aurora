#pragma once

#include "Aurora/Core/Base.h"

#include "Aurora/Core/Window.h"
#include "Aurora/Core/LayerStack.h"
#include "Aurora/Events/Event.h"
#include "Aurora/Events/ApplicationEvent.h"

#include "Aurora/Core/Timestep.h"

#include "Aurora/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Aurora {

	class Application
	{
	public:
		//构造函数
		Application(const std::string& name = "Aurora App");
		//析构函数 接口实际是被Sandbox应用程序继承，故用虚函数
		virtual ~Application();

		// 将回调函数绑定到OnEvent函数上
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window>m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


