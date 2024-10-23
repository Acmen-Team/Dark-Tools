#include <iostream>
	
#include <DTools.h>

using namespace DTools;

/*
* Dark-Tools Example
*/


// Example of using the Logger
void Example_Logger()
{
	// Create a logger
	Logger logger("Example");

	// Log a message with the different log levels
	logger.Trace("This is a trace message");
	logger.Info("This is an info message");
	logger.Warn("This is a warning message");
	logger.Error("This is an error message");
	logger.Critical("This is a critical message");

	// Log a message with formatting and arguments
	logger.Info("This is a formatted message with an argument: %s v%d.%d.%d", "Dark", 0, 1, 0);

	// Log a message with marcros
	DK_CORE_INFO("This is a core info message");
	DK_INFO("This is an info message");

	// Log a message with marcros and formatting
	DK_CORE_INFO("This is a core formatted message with an argument: %s v%d.%d.%d", "Dark", 0, 1, 0);

	// Assert a condition
	DK_ASSERT(false, "This is an assertion message");
}


int main()
{
	// Run the example
	Example_Logger();

	return std::cin.get();
}