#pragma once
#include <functional>

#include "Aurora/Debug/Instrumentor.h"
#include "Aurora/Core/Base.h"

namespace Aurora {

	// Events in Aurora are currently blocking. meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future,a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	// �¼�ϵͳ��Aurora Engine(�������棩�����������¼�����ʽ��Ƶ�,���¼�����ʱ��
	// ����Ӧ�û�ֹͣ��Ȼ�����¼���
	// ����������ܣ�һ�����õ�ʵ�ַ�ʽ��ͨ���¼����л򻺳�����ʵ���ⲿӦ�ú�����
	// �¼�������

	// �����¼�����
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// �¼�����
	// ͨ��λ�����Ƚ��¼��ֳɶ���¼����ͣ���ͨ�����ò�ͬ��λ�ֶ�,ȡ����ķ�ʽ����
	// ͬһ�¼������еĶ��Ӧ�����ֿ�
	// ��:����ƶ�����������������¼��еĲ�ͬӦ��
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
	
	// �¼�����
	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		// ���ڹ���ĳЩ���͵��¼�
		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		// �ж��¼��Ƿ񱻴���
		// �������¼�ȥ����ͬ�Ĳ�ʱ����ֹ�¼�����һ������
		bool m_Handled = false;
	};

	// �¼������� �����¼����͵����¼�
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


