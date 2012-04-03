/*
 * trace.h
 *
 *  Created on: 2012/04/01
 *      Author: ksksue
 */

#ifndef TRACE_H_
#define TRACE_H_
#include "config.h"
#include <iostream>
#include <string>

using namespace std;

class Trace {
public:
	inline Trace(const char*);
	inline Trace(const std::string&);
	inline ~Trace();

	inline void debug(const std::string&);

	static bool traceIsActive;

private:
#ifdef USE_STRING
	std::string theFunctionName;
#elif defined USE_CHAR
	std::string theFunctionName;
#elif defined USE_STRING_POINTER
	std::string* theFunctionName;
#endif
};


#endif /* TRACE_H_ */
