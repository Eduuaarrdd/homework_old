#include "utils.h"
#include <stdio.h>

int timer_from(unsigned char from) {
    size_t counter = 0;
    for (unsigned char i = from; i != 0; --i) {
        ++counter;
        printf("%c", i);
        }
    return counter;
}

// TODO(Eduard): Implement `power of` function
/*
int custom_pow(int base, int power) {
    return 0;
}
*/
