#include "from_1_to_n.h"

#include <stdio.h>


void from_1_to_n(int num) {
    if (num > 0) {
    	    num -= 1;
    	    from_1_to_n(num);
    	    if (num == 0) {
    	    printf("1"); } else {
            printf(" %d", num+1); } }
    if (num < 0) {
            num += 1;
            from_1_to_n(num);
            if (num == 0) {
            printf("1 0 -1");} else {
            printf(" %d", num-1); } } 
  }
