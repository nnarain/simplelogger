#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#include "logger/logger_base.h"
#include "logger/level.h"

/* Log Macros */

#define LOG_INFO(msg, ...)  simplelogger::log(Level::INFO,  __FILE__ ":%d" " [INFO ] " msg, __LINE__, ##__VA_ARGS__)
#define LOG_DEBUG(msg, ...) simplelogger::log(Level::DEBUG, __FILE__ ":%d" " [DEBUG] " msg, __LINE__, ##__VA_ARGS__)
#define LOG_WARN(msg, ...)  simplelogger::log(Level::WARN,  __FILE__ ":%d" " [WARN ] " msg, __LINE__, ##__VA_ARGS__)
#define LOG_ERROR(msg, ...) simplelogger::log(Level::ERROR, __FILE__ ":%d" " [ERROR] " msg, __LINE__, ##__VA_ARGS__)

namespace simplelogger
{

void log(Level level, const char * format, ...);

void addLogger(LoggerBase * logger);
void releaseLoggers();

template<typename LoggerT, typename... Args>
void registerLogger(Args... args)
{
	addLogger(new LoggerT(args...));
}

} // namespace simplelogger

#endif
