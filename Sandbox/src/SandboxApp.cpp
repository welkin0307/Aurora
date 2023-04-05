#include <Aurora.h>

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
		PushOverlay(new Aurora::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Aurora::Application* Aurora::CreateApplication()
{
	return new Sandbox();
}