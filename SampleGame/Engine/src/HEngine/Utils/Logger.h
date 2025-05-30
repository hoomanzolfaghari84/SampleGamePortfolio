#pragma once
#include <memory.h>
#include "HEngine/Core/Core.h"
#include <spdlog/spdlog.h>

namespace HEngine
{
	class HENGINE_API HLogger
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};




	// Core log macros
	#define HE_CORE_TRACE(...)    ::HEngine::HLogger::GetCoreLogger()->trace(__VA_ARGS__)
	#define HE_CORE_INFO(...)     ::HEngine::HLogger::GetCoreLogger()->info(__VA_ARGS__)
	#define HE_CORE_WARN(...)     ::HEngine::HLogger::GetCoreLogger()->warn(__VA_ARGS__)
	#define HE_CORE_ERROR(...)    ::HEngine::HLogger::GetCoreLogger()->error(__VA_ARGS__)
	#define HE_CORE_CRITICAL(...) ::HEngine::HLogger::GetCoreLogger()->critical(__VA_ARGS__)
									 
	// Client log macros		
	#define HE_TRACE(...)         ::HEngine::HLogger::GetClientLogger()->trace(__VA_ARGS__)
	#define HE_INFO(...)          ::HEngine::HLogger::GetClientLogger()->info(__VA_ARGS__)
	#define HE_WARN(...)          ::HEngine::HLogger::GetClientLogger()->warn(__VA_ARGS__)
	#define HE_ERROR(...)         ::HEngine::HLogger::GetClientLogger()->error(__VA_ARGS__)
	#define HE_CRITICAL(...)      ::HEngine::HLogger::GetClientLogger()->critical(__VA_ARGS__)

}


