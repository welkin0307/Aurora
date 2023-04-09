#include "aurpch.h"
#include "Aurora/Core/Application.h"

#include "Aurora/Core/Log.h"

#include "Aurora/Renderer/Renderer.h"

#include "Aurora/Core/Input.h"

#include <GLFW/glfw3.h>


namespace Aurora {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		AUR_PROFILE_FUNCTION();

		AUR_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = Window::Create();
		//�����¼��ص�
		m_Window->SetEventCallback(AUR_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
		AUR_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}

	void Application::PushLayer(Layer* layer)
	{
		AUR_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		AUR_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::Close()
	{
		m_Running = false;
	}

	// �ص�����ʵ��
	void Application::OnEvent(Event& e)
	{
		AUR_PROFILE_FUNCTION();

		// ͨ���¼�������������Ӧ���¼�����
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(AUR_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(AUR_BIND_EVENT_FN(Application::OnWindowResize));

			for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
			{
				if (e.Handled)
					break;
				(*it)->OnEvent(e);
			}
	}

	void Application::Run()
	{
		AUR_PROFILE_FUNCTION();

		while (m_Running)
		{
			AUR_PROFILE_SCOPE("RunLoop");

			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				{
					AUR_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}

				m_ImGuiLayer->Begin();
				{
					AUR_PROFILE_SCOPE("LayerStack OnImGuiRender");
					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
				}
				m_ImGuiLayer->End();
			}
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		AUR_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}
}
