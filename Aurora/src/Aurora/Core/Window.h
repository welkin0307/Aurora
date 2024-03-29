#pragma once

#include <sstream>

#include "Aurora/Core/Base.h"
#include "Aurora/Events/Event.h"

namespace Aurora {

	// 窗口基本属性
	// Basic Window Attributes
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Aurora Engine",
			  uint32_t width = 1280,
			  uint32_t height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	// 表示基于窗口的桌面系统抽象接口（平台无关）
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate(){}

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		// Window attribute
		// 窗口属性
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
		// It must be implemented on different platforms.
		// 它必须在不同的平台上被实现。
		static Scope<Window> Create(const WindowProps& props = WindowProps());
	};
}
