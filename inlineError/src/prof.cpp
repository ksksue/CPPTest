/*
 * prof.c
 *
 *  Created on: 2012/04/01
 *      Author: ksksue
 */
#include <stdlib.h>
#include <sys/time.h>
#include "prof.h"

double get_dtime(void){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}
