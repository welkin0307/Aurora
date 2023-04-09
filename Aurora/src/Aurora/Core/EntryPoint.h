#pragma once
#include "Aurora/Core/Base.h"

#ifdef AUR_PLATFORM_WINDOWS

extern Aurora::Application* Aurora::CreateApplication();

int main(int argc, char** argv)
{
	Aurora::Log::Init();

	AUR_PROFILE_BEGIN_SESSION("Startup", "AuroraProfile-Startup.json");
	auto app = Aurora::CreateApplication();
	AUR_PROFILE_END_SESSION();

	AUR_PROFILE_BEGIN_SESSION("Runtime", "AuroraProfile-Runtime.json");
	app->Run();
	AUR_PROFILE_END_SESSION();

	AUR_PROFILE_BEGIN_SESSION("Shutdown", "AuroraProfile-Shutdown.json");
	delete app;
	AUR_PROFILE_END_SESSION();
}

#endif
