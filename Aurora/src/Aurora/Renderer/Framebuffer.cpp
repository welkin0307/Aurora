#include "aurpch.h"
#include "Aurora/Renderer/Framebuffer.h"

#include "Aurora/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Aurora {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    AUR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		AUR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
