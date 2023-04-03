#pragma once

#include "aurpch.h"

#include "Aurora/Core.h"
#include "Aurora/Events/Event.h"

namespace Aurora {

	// 窗口基本属性
	// Basic Window Attributes
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Aurora Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	// 表示基于窗口的桌面系统抽象接口（平台无关）
	class AURORA_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate(){}

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attribute
		// 窗口属性
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		// It must be implemented on different platforms.
		// 它必须在不同的平台上被实现。
		static Window* Create(const WindowProps& props = WindowProps());
	};
}
