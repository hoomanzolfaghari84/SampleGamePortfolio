#include "Logger.h"

#pragma warning(push)
#pragma warning(disable : 4251)
#include <spdlog/sinks/stdout_color_sinks.h>

namespace HEngine {
	
	
	std::shared_ptr<spdlog::logger> HLogger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> HLogger::s_ClientLogger;

	void HLogger::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("HEngine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	
}