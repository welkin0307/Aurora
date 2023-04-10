project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Aurora/vendor/spdlog/include",
		"%{wks.location}/Aurora/src",
		"%{wks.location}/Aurora/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Aurora"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "AUR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AUR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AUR_DIST"
		runtime "Release"
		optimize "on"
