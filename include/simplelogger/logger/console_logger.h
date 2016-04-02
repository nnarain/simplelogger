
#ifndef SIMPLELOGGER_CONSOLE_LOGGER_H
#define SIMPLELOGGER_CONSOLE_LOGGER_H

#include "stream_logger.h"

#include <iostream>
#include <string>

namespace simplelogger
{

/**
	\class ConsoleLogger
	\brief Log to console window (std::cout)

	\ingroup DefaultLoggers
*/
class ConsoleLogger : public StreamLogger
{
public:
	ConsoleLogger() : 
		StreamLogger(std::cout),
		level_color_{"\x1b[0m", "\x1b[0m", "\x1b[33m", "\x1b[31m"}
	{
	}

	virtual ~ConsoleLogger()
	{
	}

	virtual void log(Level level, const char * message, size_t message_len)
	{
		os_ << level_color_[level];
		StreamLogger::log(level, message, message_len);
		os_ << "\x1b[0m";
	}

private:
	std::string level_color_[LEVEL_COUNT]; ///< ANSI color codes for level output
};

}

#endif // SIMPLELOGGER_CONSOLE_LOGGER_H
