#pragma once

#include "aurpch.h"

#include "Aurora/Core.h"
#include "Aurora/Events/Event.h"

namespace Aurora {

	// ���ڻ�������
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
	// ��ʾ���ڴ��ڵ�����ϵͳ����ӿڣ�ƽ̨�޹أ�
	class AURORA_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate(){}

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attribute
		// ��������
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		// It must be implemented on different platforms.
		// �������ڲ�ͬ��ƽ̨�ϱ�ʵ�֡�
		static Window* Create(const WindowProps& props = WindowProps());
	};
}
