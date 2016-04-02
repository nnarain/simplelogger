
#ifndef SIMPLELOGGER_STREAM_LOGGER_H
#define SIMPLELOGGER_STREAM_LOGGER_H

#include "logger_base.h"

#include <ostream>

namespace simplelogger
{

class StreamLogger : public LoggerBase
{
public:
	StreamLogger(std::ostream& os) : os_(os)
	{
	}

	virtual ~StreamLogger()
	{
	}

	virtual void log(Level level, const char * message, size_t message_len)
	{
		std::string msg(message, message_len);
		os_ << msg;
	}

protected:
	std::ostream& os_;
};

}

#endif // SIMPLELOGGER_STREAM_LOGGER_H
