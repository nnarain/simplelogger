
#ifndef SIMPLELOGGER_LEVEL_H
#define SIMPLELOGGER_LEVEL_H

namespace simplelogger
{
	/**
		\enum Level 
		\ingroup API
	*/
	enum Level
	{
		INFO = 0, ///< Informational 
		DEBUG,    ///< Debbuging
		WARN,     ///< Warning
		ERROR,    ///< Error

		LEVEL_COUNT
	};
}

#endif
