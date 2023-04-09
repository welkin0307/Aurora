#include <Aurora.h>
#include <Aurora/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Aurora {

	class AuroraPolaris : public Application
	{
	public:
		AuroraPolaris()
			: Application("Aurora Polaris")
		{
			PushLayer(new EditorLayer());
		}

		~AuroraPolaris()
		{
		}
	};

	Application* CreateApplication()
	{
		return new AuroraPolaris();
	}

}