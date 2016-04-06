
/**
	\file simplelogger.h
	\author Natesh Narain
*/

/** \defgroup API API */
/** \defgroup DefaultLoggers Provided Loggers */

#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#include "logger/logger_base.h"
#include "logger/level.h"

/**
	\defgroup LogMacros Log Macros
	@{
*/

//! Log informational message
#define LOG_INFO(msg, ...)  simplelogger::log(Level::INFO,  __FILE__ ":%d" " [INFO ] " msg "\n", __LINE__, ##__VA_ARGS__)
//! Log debug message
#define LOG_DEBUG(msg, ...) simplelogger::log(Level::DEBUG, __FILE__ ":%d" " [DEBUG] " msg "\n", __LINE__, ##__VA_ARGS__)
//! Log warning message
#define LOG_WARN(msg, ...)  simplelogger::log(Level::WARN,  __FILE__ ":%d" " [WARN ] " msg "\n", __LINE__, ##__VA_ARGS__)
//! Log error message
#define LOG_ERROR(msg, ...) simplelogger::log(Level::ERROR, __FILE__ ":%d" " [ERROR] " msg "\n", __LINE__, ##__VA_ARGS__)

/** @} */

namespace simplelogger
{

/**
	\brief Log a formatted string

	\param level Logger level
	\param format format string
	\param ... parameter list
*/
void log(Level level, const char * format, ...);

void addLogger(LoggerBase * logger);
void releaseLoggers();

/**
	\brief Allocate a logger of type LoggerT

	\tparam LoggerT Logger Type
	\tparam Args LoggerT constructor arguments
*/
template<typename LoggerT, typename... Args>
void registerLogger(Args... args)
{
	addLogger(new LoggerT(args...));
}

} // namespace simplelogger

#endif
