// About OpenGL function loaders; modern OpenGL doesn't have a standard header file and requires individual function pointers to be loaded manually.
// Helper libraries are often used for this purpose! Here we are supporting a few common ones: gl3w,glew,glad.
// You may use another loader/header of your choice (glext, glLoadGen,etc), or chose to manually implement your own.

// About GLSL version;
// The 'glsl_version' initialization parameter should be NULL (default) or a "#version XXX" string.
// On computer platform the GLSL version default to "#version 130", On OpenGL ES 3 platform it defaults to "#version 300 es"
// Only override if your GL version doesn't handle this GLSL version.See GLSL version table at the top of imgui_impl_opengl3.cpp.

#pragma once

#include "imgui.h"

IMGUI_IMPL_API bool		ImGui_ImplOpenGL3_Init(const char* glsl_version = NULL);
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_Shutdown();
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_NewFrame();
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_RenderDrawData(ImDrawData* draw_data);

// Called by Init/NewFram/Shutdown
IMGUI_IMPL_API bool     ImGui_ImplOpenGL3_CreateFontsTexture();
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_DestroyFontsTexture();
IMGUI_IMPL_API bool     ImGui_ImplOpenGL3_CreateDeviceObjects();
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_DestroyDeviceObjects();

