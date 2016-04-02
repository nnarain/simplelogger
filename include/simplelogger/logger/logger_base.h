
#ifndef SIMPLELOGGER_LOGGER_BASE_H
#define SIMPLELOGGER_LOGGER_BASE_H

#include "level.h"
#include <cstddef>

namespace simplelogger
{

class LoggerBase
{
public:
	LoggerBase()
	{
	}
	~LoggerBase()
	{
	}

	virtual void log(Level level, const char * message, size_t message_len) = 0;

private:
};

}

#endif // SIMPLELOGGER_LOGGER_BASE_H
