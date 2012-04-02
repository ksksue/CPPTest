/*
 * IntArray.cpp
 *
 *  Created on: 2012/04/02
 *      Author: ksksue
 */

#include "IntArray.h"
#include <iostream>
#include <cstdlib>

#ifdef USE_COPY_CONSTRUCTOR
#include <algorithm>
#endif

using namespace std;

IntArray::IntArray(int size) {
	m_array = new int[size];
	m_size = size;

	cout << "IntArray's constructor is called. Array size is " << m_size << endl;
}

IntArray::~IntArray() {
	delete[] m_array;
	cout << "IntArray's destructor is called. Array size is " << m_size << endl;
}

#ifdef USE_COPY_CONSTRUCTOR
IntArray::IntArray(const IntArray& other) {
	m_array = new int[other.m_size];
	m_size = other.m_size;

	copy(other.m_array, other.m_array + m_size, m_array);

	cout << "IntArray's copy constructor is called." << endl;
}
#endif

int IntArray::Size() {
	return m_size;
}

int IntArray::Get(int i) {
	CheckIndex(i);
	return m_array[i];
}

void IntArray::Set(int i, int value) {
	CheckIndex(i);
	m_array[i] = value;
}

void IntArray::CheckIndex(int i) {
	if(0 <= i && i < m_size) {
		// OK
	} else {
		// NG
		cout << "Illegal index : " << i << endl;
		exit(EXIT_FAILURE);
	}
}
