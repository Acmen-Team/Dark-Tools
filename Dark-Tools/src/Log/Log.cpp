/*************************************************
Copyright © 2020 - 2021 YX.All Rights Reserved

Date:2021-10-30 13:36
Description:Log Tools
**************************************************/

#include "Log/Log.h"
#include "Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace DTools {

	static Ref<spdlog::logger> s_CoreLogger;
	static Ref<spdlog::logger> s_ClientLogger;

	void Log::Init(const std::string& tags)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		m_Logger = spdlog::stdout_color_mt(tags);
		m_Logger->set_level(spdlog::level::trace);
	}

	void Log::Trace()
	{

	}

}