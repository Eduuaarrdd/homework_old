#include <stdlib.h>
#include <stdio.h>

#include "from_1_to_n.h"

char from_1_to_n(int num) {
    if (num == 1) {
        printf("1");
    } else {
        if (num > 0)
            printf("%c %i", from_1_to_n(num-1), num);
        else
            printf("%c %i", from_1_to_n(num+1), num);
    }
    return '\0';
  }
