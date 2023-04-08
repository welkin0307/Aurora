#include "aurpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Aurora {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		AUR_CORE_ASSERT(windowHandle,"Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		AUR_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AUR_CORE_ASSERT(status, "Failed to initialize Glad!");

		AUR_CORE_INFO("OpenGL Info:");
		AUR_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		AUR_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		AUR_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	#ifdef AUR_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			AUR_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		AUR_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}


