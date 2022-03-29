#include "utils.h"

#include <stdio.h>

#define ERROR (-1)
int timer_from(int from) {
    size_t counter = 0;
    if (from >= 0) {
    for (int i = from; i >= 0; --i) {
    if (i) {
    printf("%d ", i);  
    } else {
    printf("%d\n", i); }
    ++counter;
        }
        }
    return counter;
}

// TODO(Eduard): Implement `power of` function

int custom_pow(int base, int power) {
	int result = 1;
	if (power >=0) {
	for (int i = 0; i < power; ++i)
	result *= base;
	if (power == 0 && base == 0)  {
		 return ERROR; 
		 } } else {
		 return ERROR;
		 }
    return result;
}

