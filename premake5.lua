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
    staticruntime "off"

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
        --编译标志
        cppdialect "C++17"
        --指定链接运行时库的方式 静态链接
        staticruntime "On"
        --指定Windows SDK版本 最新
        systemversion "latest"

        --宏定义
        defines
        {
            "AUR_PLATFORM_WINDOWS",
            "AUR_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        --后构建步骤 
        postbuildcommands
        {
            --将Aurora.dll复制到Sandbox应用程序目录
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    --调试版本过滤器
    filter "configurations:Debug"
        defines "AUR_DEBUG"
        buildoptions "/MDd"
        symbols "On"
        
    --发布版本过滤器
    filter "configurations:Release"
        defines "AUR_RELEASE"
        buildoptions "/MDd"
        optimize "On"
    
    --发行版本过滤器
    filter "configurations:Dist"
        defines "AUR_DIST"
        buildoptions "/MDd"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

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
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AUR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AUR_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "AUR_RELEASE"
        buildoptions "/MDd"
        optimize "On"

    filter "configurations:Dist"
        defines "AUR_DIST"
        buildoptions "/MDd"
        optimize "On"