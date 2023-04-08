#pragma once

#include "Aurora/Core/Core.h"

#include "Aurora/Core/Window.h"
#include "Aurora/Core/LayerStack.h"
#include "Aurora/Events/Event.h"
#include "Aurora/Events/ApplicationEvent.h"

#include "Aurora/Core/Timestep.h"

#include "Aurora/ImGui/ImGuiLayer.h"

namespace Aurora {

	class Application
	{
	public:
		//���캯��
		Application();
		//�������� �ӿ�ʵ���Ǳ�SandboxӦ�ó���̳У������麯��
		virtual ~Application();

		void Run();

		// ���ص������󶨵�OnEvent������
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
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
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

