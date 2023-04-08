#pragma once
#include "Aurora/Core/Core.h"

#ifdef AUR_PLATFORM_WINDOWS

extern Aurora::Application* Aurora::CreateApplication();

int main(int argc,char** argv)
{
	Aurora::Log::Init();
	AUR_CORE_WARN("Initialized Log!");
	AUR_CLIENT_INFO("Hello Rookie!");

	auto app = Aurora::CreateApplication();
	app->Run();
	delete app;
}

#endif
