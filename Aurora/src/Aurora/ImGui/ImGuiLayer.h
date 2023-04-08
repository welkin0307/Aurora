#pragma once

#include "Aurora/Core/Layer.h"

#include "Aurora/Events/ApplicationEvent.h"
#include "Aurora/Events/KeyEvent.h"
#include "Aurora/Events/MouseEvent.h"

namespace Aurora {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

	    virtual void OnAttach() override; 
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}




