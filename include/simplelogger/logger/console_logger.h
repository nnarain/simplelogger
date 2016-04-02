
#ifndef SIMPLELOGGER_CONSOLE_LOGGER_H
#define SIMPLELOGGER_CONSOLE_LOGGER_H

#include "stream_logger.h"

#include <iostream>

namespace simplelogger
{

class ConsoleLogger : public StreamLogger
{
public:
	ConsoleLogger() : StreamLogger(std::cout)
	{
	}

	virtual ~ConsoleLogger()
	{
	}

	virtual void log(Level level, const char * message, size_t message_len)
	{
		// ...
		StreamLogger::log(level, message, message_len);
		// ...
	}

private:
};

}

#endif // SIMPLELOGGER_CONSOLE_LOGGER_H
