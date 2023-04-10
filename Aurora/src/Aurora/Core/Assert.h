#pragma once

#include "Aurora/Core/Base.h"
#include "Aurora/Core/Log.h"
#include <filesystem>

#ifdef AUR_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define AUR_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { AUR##type##ERROR(msg, __VA_ARGS__); AUR_DEBUGBREAK(); } }
#define AUR_INTERNAL_ASSERT_WITH_MSG(type, check, ...) AUR_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define AUR_INTERNAL_ASSERT_NO_MSG(type, check) AUR_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", AUR_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define AUR_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define AUR_INTERNAL_ASSERT_GET_MACRO(...) AUR_EXPAND_MACRO( AUR_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, AUR_INTERNAL_ASSERT_WITH_MSG, AUR_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define AUR_ASSERT(...) AUR_EXPAND_MACRO( AUR_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define AUR_CORE_ASSERT(...) AUR_EXPAND_MACRO( AUR_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define AUR_ASSERT(...)
#define AUR_CORE_ASSERT(...)
#endif
