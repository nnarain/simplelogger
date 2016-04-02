#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#include "logger/logger_base.h"
#include "logger/level.h"

/* Log Macros */

#define LOG_INFO(msg)  simplelogger::log(Level::INFO,  __FILE__ ":" " [INFO ] " msg)
#define LOG_DEBUG(msg) simplelogger::log(Level::DEBUG, __FILE__ ":" " [DEBUG] " msg)
#define LOG_WARN(msg)  simplelogger::log(Level::WARN,  __FILE__ ":" " [WARN ] " msg)
#define LOG_ERROR(msg) simplelogger::log(Level::ERROR, __FILE__ ":" " [ERROR] " msg)

namespace simplelogger
{

void log(Level level, const char * message);

void addLogger(LoggerBase * logger);
void releaseLoggers();

template<typename LoggerT, typename... Args>
void registerLogger(Args... args)
{
	addLogger(new LoggerT(args...));
}

} // namespace simplelogger

#endif
