# Simple Logger

A simple logging framework inspired by a logging framework I used at my internship

Usage
-----

1. Register one or more loggers
2. Use supplied log level macros to begin logging


	#include <simplelogger/simplelogger.h>

	using namespace simplelogger;

	int main()
	{
		registerLogger<ConsoleLogger>();

		LOG_INFO("Informational message");
		LOG_DEBUG("Debug message");
		LOG_WARN("Warning message");
		LOG_ERROR("Error message");

		releaseLoggers();
		return 0;
	}


The log macros use format strings with variable arguments, so you can use them the same way as `printf`

