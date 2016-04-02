
#include "simplelogger/simplelogger.h"

#include <vector>

namespace simplelogger
{

namespace
{
	std::vector<LoggerBase*> loggers;
}

void log(Level level, const char * message, size_t message_len)
{
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