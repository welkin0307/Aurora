#include "aurpch.h"
#include "Application.h"

#include "Aurora/Events/ApplicationEvent.h"
#include "Aurora/Log.h"

namespace Aurora {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if(e.IsInCategory(EventCategoryApplication))
		{
			AUR_CLIENT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AUR_CLIENT_TRACE(e);
		}

		while (true);
	}
}
