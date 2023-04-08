#pragma once

#include "Aurora/Core/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Aurora {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define AUR_CORE_TRACE(...)			  ::Aurora::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AUR_CORE_INFO(...)			  ::Aurora::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AUR_CORE_WARN(...)			  ::Aurora::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AUR_CORE_ERROR(...)			  ::Aurora::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AUR_CORE_FATAL(...)			  ::Aurora::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define AUR_CORE_CRITICAL(...)        ::Aurora::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define AUR_CLIENT_TRACE(...)		  ::Aurora::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AUR_CLIENT_INFO(...)		  ::Aurora::Log::GetClientLogger()->info(__VA_ARGS__)
#define AUR_CLIENT_WARN(...)		  ::Aurora::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AUR_CLIENT_ERROR(...)		  ::Aurora::Log::GetClientLogger()->error(__VA_ARGS__)
#define AUR_CLIENT_FATAL(...)		  ::Aurora::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define AUR_CLIENT_CRITICAL(...)      ::Aurora::Log::GetClientLogger()->critical(__VA_ARGS__)