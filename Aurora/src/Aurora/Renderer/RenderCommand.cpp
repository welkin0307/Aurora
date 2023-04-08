#include "aurpch.h"
#include "Aurora/Renderer/RenderCommand.h"

namespace Aurora {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
