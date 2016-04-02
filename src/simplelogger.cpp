
#include "simplelogger/simplelogger.h"

#include <vector>

#include <stdarg.h>
#include <string.h>
#include <stdio.h>

namespace simplelogger
{

namespace
{
	std::vector<LoggerBase*> loggers;
}

void log(Level level, const char * format, ...)
{
	va_list args;
	char message[256];

	va_start(args, format);
	vsprintf(message, format, args);
	va_end(args);

	size_t message_len = strlen(message);

	for(LoggerBase * logger : loggers)
	{
		logger->log(level, message, message_len);
	}
}

void addLogger(LoggerBase * logger)
{
	loggers.push_back(logger);
}

void releaseLoggers()
{
	for(LoggerBase* logger : loggers)
	{
		delete logger;
	}
}

}