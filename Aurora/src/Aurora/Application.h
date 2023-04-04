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
		//���캯��
		Application();
		//�������� �ӿ�ʵ���Ǳ�SandboxӦ�ó���̳У������麯��
		virtual ~Application();

		void Run();

		// ���ص������󶨵�OnEvent������
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


