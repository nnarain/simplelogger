
#ifndef SIMPLELOGGER_STREAM_LOGGER_H
#define SIMPLELOGGER_STREAM_LOGGER_H

#include "logger_base.h"

#include <ostream>

namespace simplelogger
{

/**
	\class StreamLogger
	\brief Log to an output stream object

	\ingroup DefaultLoggers
*/
class StreamLogger : public LoggerBase
{
public:
	/**
		\param os output stream to log to
	*/
	StreamLogger(std::ostream& os) : os_(os)
	{
	}

	virtual ~StreamLogger()
	{
	}

	virtual void log(Level level, const char * message, size_t message_len)
	{
		std::string msg(message);
		os_ << msg;
	}

protected:
	std::ostream& os_;
};

}

#endif // SIMPLELOGGER_STREAM_LOGGER_H
