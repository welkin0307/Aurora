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

// ��־ϵͳ�������漰Ƶ���޸ģ�������ӽ�Ԥ����ͷ�ļ����ӿ�����ٶ�
#include "Aurora/Core/Log.h"

#include "Aurora/Debug/Instrumentor.h"

#ifdef AUR_PLATFORM_WINDOWS
#include <Windows.h>
#endif // 