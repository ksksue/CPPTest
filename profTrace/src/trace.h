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
	Trace(const char*);
	Trace(const std::string&);
	~Trace();

	void debug(const std::string&);

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


#ifdef USE_STRING
#ifdef USE_INLINE
inline
#endif
Trace::Trace(const std::string &name) :
		theFunctionName(name) {
	if (traceIsActive) {
#ifdef NO_COUT
#else
		std::cout << "Enter function " << name << '\n';
#endif;
	}
}
#elif defined USE_CHAR
#ifdef USE_INLINE
inline
#endif
Trace::Trace(const char *name) :
		theFunctionName(name) {
	if (traceIsActive) {
#ifdef NO_COUT
#else
		std::cout << "Enter function " << name << '\n';
#endif
	}
}
#elif defined USE_STRING_POINTER
#ifdef USE_INLINE
inline
#endif
Trace::Trace(const char *name) :
		theFunctionName(0) {
	if (traceIsActive) {
		theFunctionName = new std::string(name);
#ifdef NO_COUT
#else
		std::cout << "Enter function " << name << '\n';
#endif
	}
}
#endif

#ifdef USE_INLINE
inline
#endif
void Trace::debug(const std::string &msg) {
	if (traceIsActive) {
		std::cout << msg << '\n';
	}
}

#ifdef USE_INLINE
inline
#endif
Trace::~Trace() {
	if (traceIsActive) {
#ifdef NO_COUT
#else
#ifdef USE_STRING
		std::cout << "Exit  function " << theFunctionName << '\n';
#elif defined USE_CHAR
		std::cout << "Exit  function " << theFunctionName << '\n';
#elif defined USE_STRING_POINTER
		std::cout << "Exit  function " << *theFunctionName << '\n';
#endif
#endif

#ifdef defined USE_STRING_POINTER
		delete theFunctionName;
#endif
	}
}

#endif /* TRACE_H_ */
