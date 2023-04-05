#include <Aurora.h>

#include "imgui/imgui.h"

class ExampleLayer :public Aurora::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Aurora::Input::IsKeyPressed(AUR_KEY_TAB))
		{
			AUR_CLIENT_INFO("Tab key is pressed (poll)!");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Aurora::Event& event) override
	{
		if (event.GetEventType() == Aurora::EventType::KeyPressed)
		{
			Aurora::KeyPressedEvent& e = (Aurora::KeyPressedEvent&)event;
			if (e.GetKeyCode() == AUR_KEY_TAB)
			{
				AUR_CLIENT_TRACE("Tab key is pressed (event)!");
			}
			AUR_CLIENT_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};
class Sandbox : public Aurora::Application 
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Aurora::Application* Aurora::CreateApplication()
{
	return new Sandbox();
}