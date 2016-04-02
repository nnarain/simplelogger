#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#include "logger/logger_base.h"

namespace simplelogger
{

void log(Level level, const char * message, size_t message_len);

void addLogger(LoggerBase * logger);
void releaseLoggers();

template<typename LoggerT, typename... Args>
void registerLogger(Args... args)
{
	addLogger(new LoggerT(args...));
}

} // namespace simplelogger

#endif
