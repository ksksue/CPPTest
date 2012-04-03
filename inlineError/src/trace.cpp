/*
 * trace.cpp
 *
 *  Created on: 2012/04/04
 *      Author: ksksue
 */
#include "trace.h"

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
