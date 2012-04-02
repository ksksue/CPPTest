/*
 * IntArray.h
 *
 *  Created on: 2012/04/02
 *      Author: keisuke
 */

#ifndef INTARRAY_H_
#define INTARRAY_H_
#include "config.h"

class IntArray {
public:
	IntArray(int size);
	~IntArray();

#ifdef USE_COPY_CONSTRUCTOR
	IntArray(const IntArray& other);
#endif

public:
	int Size();
	int Get(int i);
	void Set(int i, int value);

private:
	void CheckIndex(int i);

private:
	int* m_array;
	int  m_size;
};

#endif /* INTARRAY_H_ */
