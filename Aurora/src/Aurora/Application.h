#pragma once

#include "Core.h"

#include "Window.h"
#include "Aurora/LayerStack.h"
#include "Aurora/Events/Event.h"
#include "Aurora/Events/ApplicationEvent.h"

#include "Aurora/ImGui/ImGuiLayer.h"

#include "Aurora/Renderer/Shader.h"
#include "Aurora/Renderer/Buffer.h"
#include "Aurora/Renderer/VertexArray.h"

#include "Aurora/Renderer/OrthographicCamera.h"

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

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window>m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		//unsigned int m_VertexArray;
		//std::unique_ptr<Shader> m_Shader;
		//std::unique_ptr<VertexBuffer> m_VertexBuffer;
		//std::unique_ptr<IndexBuffer> m_IndexBuffer;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


