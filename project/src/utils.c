#include "utils.h"
#include <stdio.h>

int timer_from(int from) {
    size_t counter = 0;
    if (from >= 0) {
    for (int i = from; i >= 0; --i) {
    printf("%d", i);    
        ++counter;
    if (i)
    	printf(" "); 
    else
    	printf("\n");	   
        }
        }
    return counter;
}

// TODO(Eduard): Implement `power of` function
/*
int custom_pow(int base, int power) {
    return 0;
}
*/
