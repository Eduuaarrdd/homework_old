#include <stdlib.h>
#include <stdio.h>

#include "recs.h"

char recursia(int num) {
    if (num == 1) {
        printf("1");
    } else {
        if (num > 0)
            printf("%c %i", recursia(num-1), num);
        else
            printf("%c %i", recursia(num+1), num);
    }
    return '\0';
  }
