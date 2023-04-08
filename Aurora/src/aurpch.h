#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// 日志系统并不会涉及频繁修改，这里添加进预编译头文件来加快编译速度
#include "Aurora/Core/Log.h"

#include "Aurora/Debug/Instrumentor.h"

#ifdef AUR_PLATFORM_WINDOWS
#include <Windows.h>
#endif // 