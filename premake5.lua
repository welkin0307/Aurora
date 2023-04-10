include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Aurora"
	architecture "x86_64"
	startproject "AuroraPolaris"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Aurora/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Aurora/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Aurora/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Aurora/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Aurora/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Aurora/vendor/entt/include"

group "Dependencies"
	include "vendor/premake"
	include "Aurora/vendor/GLFW"
	include "Aurora/vendor/Glad"
	include "Aurora/vendor/imgui"
group ""

include "Aurora"
include "Sandbox" 
include "AuroraPolaris"
  