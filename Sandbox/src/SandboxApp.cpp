#include <Aurora.h>
#include <Aurora/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Aurora::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

Aurora::Application* Aurora::CreateApplication()
{
	return new Sandbox();
}