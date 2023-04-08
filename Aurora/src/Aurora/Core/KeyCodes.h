#pragma once

namespace Aurora
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define AUR_KEY_SPACE           ::Aurora::Key::Space
#define AUR_KEY_APOSTROPHE      ::Aurora::Key::Apostrophe    /* ' */
#define AUR_KEY_COMMA           ::Aurora::Key::Comma         /* , */
#define AUR_KEY_MINUS           ::Aurora::Key::Minus         /* - */
#define AUR_KEY_PERIOD          ::Aurora::Key::Period        /* . */
#define AUR_KEY_SLASH           ::Aurora::Key::Slash         /* / */
#define AUR_KEY_0               ::Aurora::Key::D0
#define AUR_KEY_1               ::Aurora::Key::D1
#define AUR_KEY_2               ::Aurora::Key::D2
#define AUR_KEY_3               ::Aurora::Key::D3
#define AUR_KEY_4               ::Aurora::Key::D4
#define AUR_KEY_5               ::Aurora::Key::D5
#define AUR_KEY_6               ::Aurora::Key::D6
#define AUR_KEY_7               ::Aurora::Key::D7
#define AUR_KEY_8               ::Aurora::Key::D8
#define AUR_KEY_9               ::Aurora::Key::D9
#define AUR_KEY_SEMICOLON       ::Aurora::Key::Semicolon     /* ; */
#define AUR_KEY_EQUAL           ::Aurora::Key::Equal         /* = */
#define AUR_KEY_A               ::Aurora::Key::A
#define AUR_KEY_B               ::Aurora::Key::B
#define AUR_KEY_C               ::Aurora::Key::C
#define AUR_KEY_D               ::Aurora::Key::D
#define AUR_KEY_E               ::Aurora::Key::E
#define AUR_KEY_F               ::Aurora::Key::F
#define AUR_KEY_G               ::Aurora::Key::G
#define AUR_KEY_H               ::Aurora::Key::H
#define AUR_KEY_I               ::Aurora::Key::I
#define AUR_KEY_J               ::Aurora::Key::J
#define AUR_KEY_K               ::Aurora::Key::K
#define AUR_KEY_L               ::Aurora::Key::L
#define AUR_KEY_M               ::Aurora::Key::M
#define AUR_KEY_N               ::Aurora::Key::N
#define AUR_KEY_O               ::Aurora::Key::O
#define AUR_KEY_P               ::Aurora::Key::P
#define AUR_KEY_Q               ::Aurora::Key::Q
#define AUR_KEY_R               ::Aurora::Key::R
#define AUR_KEY_S               ::Aurora::Key::S
#define AUR_KEY_T               ::Aurora::Key::T
#define AUR_KEY_U               ::Aurora::Key::U
#define AUR_KEY_V               ::Aurora::Key::V
#define AUR_KEY_W               ::Aurora::Key::W
#define AUR_KEY_X               ::Aurora::Key::X
#define AUR_KEY_Y               ::Aurora::Key::Y
#define AUR_KEY_Z               ::Aurora::Key::Z
#define AUR_KEY_LEFT_BRACKET    ::Aurora::Key::LeftBracket   /* [ */
#define AUR_KEY_BACKSLASH       ::Aurora::Key::Backslash     /* \ */
#define AUR_KEY_RIGHT_BRACKET   ::Aurora::Key::RightBracket  /* ] */
#define AUR_KEY_GRAVE_ACCENT    ::Aurora::Key::GraveAccent   /* ` */
#define AUR_KEY_WORLD_1         ::Aurora::Key::World1        /* non-US #1 */
#define AUR_KEY_WORLD_2         ::Aurora::Key::World2        /* non-US #2 */

/* Function keys */
#define AUR_KEY_ESCAPE          ::Aurora::Key::Escape
#define AUR_KEY_ENTER           ::Aurora::Key::Enter
#define AUR_KEY_TAB             ::Aurora::Key::Tab
#define AUR_KEY_BACKSPACE       ::Aurora::Key::Backspace
#define AUR_KEY_INSERT          ::Aurora::Key::Insert
#define AUR_KEY_DELETE          ::Aurora::Key::Delete
#define AUR_KEY_RIGHT           ::Aurora::Key::Right
#define AUR_KEY_LEFT            ::Aurora::Key::Left
#define AUR_KEY_DOWN            ::Aurora::Key::Down
#define AUR_KEY_UP              ::Aurora::Key::Up
#define AUR_KEY_PAGE_UP         ::Aurora::Key::PageUp
#define AUR_KEY_PAGE_DOWN       ::Aurora::Key::PageDown
#define AUR_KEY_HOME            ::Aurora::Key::Home
#define AUR_KEY_END             ::Aurora::Key::End
#define AUR_KEY_CAPS_LOCK       ::Aurora::Key::CapsLock
#define AUR_KEY_SCROLL_LOCK     ::Aurora::Key::ScrollLock
#define AUR_KEY_NUM_LOCK        ::Aurora::Key::NumLock
#define AUR_KEY_PRINT_SCREEN    ::Aurora::Key::PrintScreen
#define AUR_KEY_PAUSE           ::Aurora::Key::Pause
#define AUR_KEY_F1              ::Aurora::Key::F1
#define AUR_KEY_F2              ::Aurora::Key::F2
#define AUR_KEY_F3              ::Aurora::Key::F3
#define AUR_KEY_F4              ::Aurora::Key::F4
#define AUR_KEY_F5              ::Aurora::Key::F5
#define AUR_KEY_F6              ::Aurora::Key::F6
#define AUR_KEY_F7              ::Aurora::Key::F7
#define AUR_KEY_F8              ::Aurora::Key::F8
#define AUR_KEY_F9              ::Aurora::Key::F9
#define AUR_KEY_F10             ::Aurora::Key::F10
#define AUR_KEY_F11             ::Aurora::Key::F11
#define AUR_KEY_F12             ::Aurora::Key::F12
#define AUR_KEY_F13             ::Aurora::Key::F13
#define AUR_KEY_F14             ::Aurora::Key::F14
#define AUR_KEY_F15             ::Aurora::Key::F15
#define AUR_KEY_F16             ::Aurora::Key::F16
#define AUR_KEY_F17             ::Aurora::Key::F17
#define AUR_KEY_F18             ::Aurora::Key::F18
#define AUR_KEY_F19             ::Aurora::Key::F19
#define AUR_KEY_F20             ::Aurora::Key::F20
#define AUR_KEY_F21             ::Aurora::Key::F21
#define AUR_KEY_F22             ::Aurora::Key::F22
#define AUR_KEY_F23             ::Aurora::Key::F23
#define AUR_KEY_F24             ::Aurora::Key::F24
#define AUR_KEY_F25             ::Aurora::Key::F25

/* Keypad */
#define AUR_KEY_KP_0            ::Aurora::Key::KP0
#define AUR_KEY_KP_1            ::Aurora::Key::KP1
#define AUR_KEY_KP_2            ::Aurora::Key::KP2
#define AUR_KEY_KP_3            ::Aurora::Key::KP3
#define AUR_KEY_KP_4            ::Aurora::Key::KP4
#define AUR_KEY_KP_5            ::Aurora::Key::KP5
#define AUR_KEY_KP_6            ::Aurora::Key::KP6
#define AUR_KEY_KP_7            ::Aurora::Key::KP7
#define AUR_KEY_KP_8            ::Aurora::Key::KP8
#define AUR_KEY_KP_9            ::Aurora::Key::KP9
#define AUR_KEY_KP_DECIMAL      ::Aurora::Key::KPDecimal
#define AUR_KEY_KP_DIVIDE       ::Aurora::Key::KPDivide
#define AUR_KEY_KP_MULTIPLY     ::Aurora::Key::KPMultiply
#define AUR_KEY_KP_SUBTRACT     ::Aurora::Key::KPSubtract
#define AUR_KEY_KP_ADD          ::Aurora::Key::KPAdd
#define AUR_KEY_KP_ENTER        ::Aurora::Key::KPEnter
#define AUR_KEY_KP_EQUAL        ::Aurora::Key::KPEqual

#define AUR_KEY_LEFT_SHIFT      ::Aurora::Key::LeftShift
#define AUR_KEY_LEFT_CONTROL    ::Aurora::Key::LeftControl
#define AUR_KEY_LEFT_ALT        ::Aurora::Key::LeftAlt
#define AUR_KEY_LEFT_SUPER      ::Aurora::Key::LeftSuper
#define AUR_KEY_RIGHT_SHIFT     ::Aurora::Key::RightShift
#define AUR_KEY_RIGHT_CONTROL   ::Aurora::Key::RightControl
#define AUR_KEY_RIGHT_ALT       ::Aurora::Key::RightAlt
#define AUR_KEY_RIGHT_SUPER     ::Aurora::Key::RightSuper
#define AUR_KEY_MENU            ::Aurora::Key::Menu