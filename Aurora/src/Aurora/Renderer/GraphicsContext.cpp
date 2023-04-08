#include "aurpch.h"
#include "Aurora/Renderer/GraphicsContext.h"

#include "Aurora/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Aurora {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    AUR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		AUR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}