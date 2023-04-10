#pragma once
#include <functional>

#include "Aurora/Debug/Instrumentor.h"
#include "Aurora/Core/Base.h"

namespace Aurora {

	// Events in Aurora are currently blocking. meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future,a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	// 事件系统在Aurora Engine(极光引擎）中是以阻塞事件的形式设计的,当事件发生时，
	// 整个应用会停止，然后处理事件。
	// 对于这个功能，一个更好的实现方式是通过事件队列或缓冲区来实现外部应用和引擎
	// 事件交互。

	// 描述事件类型
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// 事件分类
	// 通过位运算先将事件分成多个事件类型，再通过设置不同的位字段,取掩码的方式来将
	// 同一事件类型中的多个应用区分开
	// 例:鼠标移动和鼠标滚动属于鼠标事件中的不同应用
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput       = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
	
	// 事件基类
	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		// 用于过滤某些类型的事件
		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		// 判断事件是否被处理
		// 当调度事件去处理不同的层时，阻止事件被进一步传递
		bool m_Handled = false;
	};

	// 事件调度器 基于事件类型调度事件
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled |= func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}


 
}


