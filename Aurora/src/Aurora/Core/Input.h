#pragma once

#include <glm/glm.hpp>

#include "Aurora/Core/KeyCodes.h"
#include "Aurora/Core/MouseCodes.h"

namespace Aurora {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
