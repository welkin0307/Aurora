#pragma once

namespace Aurora
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define AUR_MOUSE_BUTTON_0      ::Aurora::Mouse::Button0
#define AUR_MOUSE_BUTTON_1      ::Aurora::Mouse::Button1
#define AUR_MOUSE_BUTTON_2      ::Aurora::Mouse::Button2
#define AUR_MOUSE_BUTTON_3      ::Aurora::Mouse::Button3
#define AUR_MOUSE_BUTTON_4      ::Aurora::Mouse::Button4
#define AUR_MOUSE_BUTTON_5      ::Aurora::Mouse::Button5
#define AUR_MOUSE_BUTTON_6      ::Aurora::Mouse::Button6
#define AUR_MOUSE_BUTTON_7      ::Aurora::Mouse::Button7
#define AUR_MOUSE_BUTTON_LAST   ::Aurora::Mouse::ButtonLast
#define AUR_MOUSE_BUTTON_LEFT   ::Aurora::Mouse::ButtonLeft
#define AUR_MOUSE_BUTTON_RIGHT  ::Aurora::Mouse::ButtonRight
#define AUR_MOUSE_BUTTON_MIDDLE ::Aurora::Mouse::ButtonMiddle

