workspace "Dark-Tools"
	architecture "x86_64"
	startproject "Dark-Render"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder(solution directory)
IncludeDir = {}

project "Dark-Tools"
	location "Dark-Tools"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
	}

	links
	{
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "DKTL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DKTL_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "DKTL_Dist"
		runtime "Release"
		optimize "On"