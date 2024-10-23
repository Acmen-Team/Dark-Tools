/*************************************************
Copyright © 2020 - 2024 YxY. All Rights Reserved

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Date: 2024/10/23
Description: Logger
**************************************************/
#include "Logger/Logger.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/bundled/format.h>

namespace DTools
{
	class Logger::LogImpl
	{
	public:
		LogImpl(const char* tag)
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");
			m_CoreLogger = spdlog::stdout_color_mt(tag);
			m_CoreLogger->set_level(spdlog::level::trace);
		}

		std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }

	private:
		std::shared_ptr<spdlog::logger> m_CoreLogger;
	};

	Logger::Logger(const char* tag)
		: m_LogImpl(CreateScope<LogImpl>(tag))
	{
	}

	Logger::~Logger()
	{
		m_LogImpl.reset();
	}


	void Logger::Trace(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		char buffer[1024];
		vsprintf_s(buffer, format, args);
		va_end(args);
		m_LogImpl->GetCoreLogger()->trace(buffer);
	}

	void Logger::Info(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		char buffer[1024];
		vsprintf_s(buffer, format, args);
		va_end(args);
		m_LogImpl->GetCoreLogger()->info(buffer);
	}

	void Logger::Warn(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		char buffer[1024];
		vsprintf_s(buffer, format, args);
		va_end(args);
		m_LogImpl->GetCoreLogger()->warn(buffer);
	}

	void Logger::Error(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		char buffer[1024];
		vsprintf_s(buffer, format, args);
		va_end(args);
		m_LogImpl->GetCoreLogger()->error(buffer);
	}

	void Logger::Critical(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		char buffer[1024];
		vsprintf_s(buffer, format, args);
		va_end(args);
		m_LogImpl->GetCoreLogger()->critical(buffer);
	}

	// Global Logger
	Ref<Logger> s_CoreLogger = CreateRef<Logger>("Core");
	Ref<Logger> s_ClientLogger = CreateRef<Logger>("Client");

} // namespace DTools