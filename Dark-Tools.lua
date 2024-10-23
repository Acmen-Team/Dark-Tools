workspace "Dark-Tools"
	architecture "x86_64"
	startproject "Tools-Example"

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
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/include",
		"%{prj.name}/vendor/spdlog/include",
	}

	links
	{
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"DK_PLATFORM_WINDOWS",
			"DK_DYNAMIC_LINK",
			"DK_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Tools-Example/\"")
		}

	filter "configurations:Debug"
		defines "DK_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "DK_Dist"
		runtime "Release"
		optimize "On"

project "Tools-Example"
	location "Tools-Example"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Dark-Tools/include",
	}

	links
	{
		"Dark-Tools"
	}
	
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"DK_PLATFORM_WINDOWS",
			"DK_DYNAMIC_LINK",
			"DK_ENABLE_ASSERTS",	
		}

	filter "configurations:Debug"
		defines "DK_DEBUG"
		runtime "Debug"
		kind "ConsoleApp"
		symbols "On"

	filter "configurations:Release"
		defines "DK_RELEASE"
		runtime "Release"
		kind "ConsoleApp"
		optimize "On"

	filter "configurations:Dist"
		defines "DK_Dist"
		runtime "Release"
		kind "ConsoleApp"
		optimize "On"