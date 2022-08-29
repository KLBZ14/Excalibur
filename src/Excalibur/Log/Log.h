#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

class Log
{
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }

private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
};

#ifdef EX_DEBUG
#define EX_CORE_ERROR(...) ::Log::getCoreLogger()->error(__VA_ARGS__)
#define EX_CORE_WARN(...) ::Log::getCoreLogger()->warn(__VA_ARGS__)
#define EX_CORE_INFO(...) ::Log::getCoreLogger()->info(__VA_ARGS__)
#else
#define EX_CORE_ERROR(...) 
#define EX_CORE_WARN(...) 
#define EX_CORE_INFO(...) 
#endif
