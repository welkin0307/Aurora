#pragma once
#include "aurpch.h"
#include "Aurora/Core/Base.h"
#include "Aurora/Core/KeyCodes.h"
#include "Aurora/Core/MouseCodes.h"

namespace Aurora {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
