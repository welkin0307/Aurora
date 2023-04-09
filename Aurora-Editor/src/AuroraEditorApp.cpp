#include <Aurora.h>
#include <Aurora/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Aurora {

	class AuroraEditor : public Application
	{
	public:
		AuroraEditor()
			: Application("Aurora Editor")
		{
			PushLayer(new EditorLayer());
		}

		~AuroraEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new AuroraEditor();
	}

}