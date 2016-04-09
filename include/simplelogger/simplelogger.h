
/**
	\file simplelogger.h
	\author Natesh Narain
*/

/** \defgroup API API */
/** \defgroup DefaultLoggers Provided Loggers */

#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#ifndef FILE_NAME
#	define FILE_NAME __FILE__
#endif

#include "logger/logger_base.h"
#include "logger/level.h"

/**
	\defgroup LogMacros Log Macros
	@{
*/

//! Log informational message
#define LOG_INFO(msg, ...)  simplelogger::log(simplelogger::Level::INFO,  FILE_NAME ":%d" " [INFO ] " msg "\n", __LINE__, ##__VA_ARGS__)
//! Log debug message
#define LOG_DEBUG(msg, ...) simplelogger::log(simplelogger::Level::DEBUG, FILE_NAME ":%d" " [DEBUG] " msg "\n", __LINE__, ##__VA_ARGS__)
//! Log warning message
#define LOG_WARN(msg, ...)  simplelogger::log(simplelogger::Level::WARN,  FILE_NAME ":%d" " [WARN ] " msg "\n", __LINE__, ##__VA_ARGS__)
//! Log error message
#define LOG_ERROR(msg, ...) simplelogger::log(simplelogger::Level::ERROR, FILE_NAME ":%d" " [ERROR] " msg "\n", __LINE__, ##__VA_ARGS__)

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
