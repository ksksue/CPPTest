/*
 * main.cpp
 *
 *  Created on: 2012/04/02
 *      Author: ksksue
 */

#include <iostream>
#include "IntArray.h"

using namespace std;

void Viss(int num) {
	cout << "Viss : No." << num << endl;
}

void Show(IntArray array) {
	Viss(2);
	for(int i=0; i<array.Size(); ++i) {
		cout << array.Get(i) << ' ';
	}
	cout << endl;
	Viss(3);
}

int main() {
	IntArray array0to9(10);

	for(int i=0; i<array0to9.Size(); ++i) {
		array0to9.Set(i,i);
	}

	Viss(1);
	Show(array0to9);
	Viss(4);
}
