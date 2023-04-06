--工作空间
workspace "Aurora"
    --项目构建架构
    architecture "x64"
    --设置启动项目
    startproject "Sandbox"

    --解决方案版本 
    configurations
    {
        --调试版本 开启所有调试功能
        "Debug",
        --发布版本 保留部分调试功能，如：日志系统等，开启优化
        "Release",
        --发行版本 移除全部调试功能，保证性能最优
        "Dist"
    }

--构建类型(Debug/Release/Dist)-系统/平台信息(Windows/Mac)-构建架构
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- 包含相对于根文件夹的目录
IncludeDir = {}
IncludeDir["GLFW"] = "Aurora/vendor/GLFW/include"
IncludeDir["Glad"] = "Aurora/vendor/Glad/include"
IncludeDir["ImGui"] = "Aurora/vendor/imgui"
IncludeDir["glm"] = "Aurora/vendor/glm"

include "Aurora/vendor/GLFW"
include "Aurora/vendor/Glad"
include "Aurora/vendor/imgui"

--项目
project "Aurora"
    --项目位置
    location "Aurora"
    --项目类型 动态库(.dll)
    kind "StaticLib"
    --语言
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    --构建目录
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    --中间文件目录
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    --添加预编译头文件
    pchheader "aurpch.h"
    pchsource "Aurora/src/aurpch.cpp"

    --包含文件
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    --依赖库路径
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    --链接到项目
    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    --Windows平台过滤器
    filter "system:windows"
        --指定Windows SDK版本 最新
        systemversion "latest"

        --宏定义
        defines
        {
            "AUR_PLATFORM_WINDOWS",
            "AUR_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    --调试版本过滤器
    filter "configurations:Debug"
        defines "AUR_DEBUG"
        runtime "Debug"
        symbols "On"
        
    --发布版本过滤器
    filter "configurations:Release"
        defines "AUR_RELEASE"
        runtime "Release"
        optimize "On"
    
    --发行版本过滤器
    filter "configurations:Dist"
        defines "AUR_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
	staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"        
    }

    includedirs
    {
        "Aurora/vendor/spdlog/include",
        "Aurora/src",
        "Aurora/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Aurora"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "AUR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AUR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "AUR_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "AUR_DIST"
        runtime "Release"
        optimize "On"