#include "utils.h"

int is_prime(int num) {
    if (num > 1) {
        for (int i = 2; i < num/2; i++)
        if (num % i == 0) {
		return 0;
	}
	return 1;
    }
    	return 0;
}
