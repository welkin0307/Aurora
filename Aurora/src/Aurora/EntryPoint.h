#pragma once

#ifdef AUR_PLATFORM_WINDOWS

extern Aurora::Application* Aurora::CreateApplication();

int main(int argc,char** argv)
{
	Aurora::Log::Init();
	AUR_CORE_WARN("Initialized Log!");
	AUR_CLIENT_INFO("Hello Rookie!");

	int a = 10;
	AUR_CLIENT_INFO("Hello! Var = {0}", a);

	auto app = Aurora::CreateApplication();
	app->Run();
	delete app;
}

#endif
