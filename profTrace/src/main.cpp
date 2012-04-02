/*
 * testcpp.cpp
 *
 *  Created on: 2012/04/01
 *      Author: ksksue
 */

#include "config.h"
#include "trace.h"
#include "prof.h"

#include <iostream>
#include <string>
#include <sys/time.h>

using namespace std;

bool Trace::traceIsActive = true;

inline int addOne(int x) {

#ifdef USE_STRING
	// stringを使ったバージョン
	string name = "addOne()";
	Trace trc(name);
#elif defined USE_CHAR
	// charポインタを使ったバージョン
	char* name = "addOne()";
	Trace trc(name);
#elif defined USE_STRING_POINTER
	// 内部でstringポインタを使ったバージョン
	char* name = "addOne()";
	Trace trc(name);
#endif
	return x + 1;
}

int main() {
	double d0,d1;
	d0 = get_dtime();

	for (long i = 0; i < 10000000; ++i) {
		int y = addOne(i);
	}
	d1 = get_dtime();

	cout << "use ";
#ifdef USE_INLINE
	cout << "inline ";
#endif
#ifdef USE_STRING
	cout << "string ";
#elif defined USE_CHAR
	cout << "char ";
#elif defined USE_STRING_POINTER
	cout << "string-pointer ";
#endif
	cout << "time : " << (d1-d0) << endl;
	return 0;
}
