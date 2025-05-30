-- premake5.lua
workspace "HEGame"
   architecture "x64"
   configurations { "Debug", "Release" }


outDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HEngine"
   kind "SharedLib"
   language "C++"
   targetdir ("bin/" .. outDir .. "/%{prj.name}")

   objdir ("bin-int/" .. outDir .. "/%{prj.name}")

   files { "**.h", "**.c" }
--    files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

   include {
    
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"