#include "Log.h"


std::shared_ptr<spdlog::logger> Log::s_CoreLogger;


void Log::Init()
{
	spdlog::set_pattern("%^[&T] %n: %v%$x");

	s_CoreLogger = spdlog::stdout_color_mt("Excalibur");
	s_CoreLogger->set_level(spdlog::level::trace);
}
