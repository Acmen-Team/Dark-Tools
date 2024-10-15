/*************************************************
Copyright © 2020 - 2024 YxY.All Rights Reserved

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

Date:2020-12-6 23:34
Description:Log System
**************************************************/
#pragma once

#include "Macro/DynamicLinkMacros.h"

namespace DTools {

	class DARK_API Log
	{
	public:
		void Init(const std::string& tags);

		void Trace();
	private:
		Ref<spdlog::logger> m_Logger;
	};

}

// Core log macros
#define DK_CORE_TRACE(...)		Log::GetCoreLogger()->trace(__VA_ARGS__);
#define DK_CORE_INFO(...)		Log::GetCoreLogger()->info(__VA_ARGS__);
#define DK_CORE_WARN(...)		Log::GetCoreLogger()->warn(__VA_ARGS__);
#define DK_CORE_ERROR(...)		Log::GetCoreLogger()->error(__VA_ARGS__);
#define DK_CORE_FATAL(...)		Log::GetCoreLogger()->fatal(__VA_ARGS__);

// App log macros
#define DK_TRACE(...)			Log::GetClientLogger()->trace(__VA_ARGS__);
#define DK_INFO(...)			Log::GetClientLogger()->info(__VA_ARGS__);
#define DK_WARN(...)			Log::GetClientLogger()->warn(__VA_ARGS__);
#define DK_ERROR(...)			Log::GetClientLogger()->error(__VA_ARGS__);
#define DK_FATAL(...)			Log::GetClientLogger()->fatal(__VA_ARGS__);

/*
* Asserts are used to check if a condition is true, if not, the program will stop and print the error message.
*/
#ifdef DK_ENABLE_ASSERTS
#define DK_ASSERT(x, ...) { if(!(x)) { DK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define DK_CORE_ASSERT(x, ...) { if(!(x)) { DK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define DK_ASSERT(x, ...)
#define DK_CORE_ASSERT(x, ...)
#endif