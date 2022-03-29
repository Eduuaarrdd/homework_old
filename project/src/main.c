#include "from_1_to_n.h"
#include "is_prime.h"
#include "utils.h"


#include <stdio.h>
#include <stdlib.h>

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG  (-2)

#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3
#define TST_MOD_RECURS  4

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }
    char* end = NULL;
    int test_case = strtol(argv[1], &end, 10);
    if (*end != '\0') {
      return ERR_ARGS_COUNT;
      }
    const char* data = argv[2];

    switch (test_case) {
        case TST_FOO_FIX:
        if (argc == 3) {
            int to = strtol(data, &end, 10);
            if (*end != '\0') {
      		return ERR_ARGS_COUNT;
		}
            printf("%d", timer_from(to));
            break; 
            }
            return ERR_ARGS_COUNT;
            break;
        case TST_FOO_IMPL: 
            if (argc == 4) {
                 int base = strtol(data, &end, 10);
                 if (*end != '\0') {
      			return ERR_ARGS_COUNT; 
      			}
		int pow = strtol(argv[3], &end, 10);
                 if (*end != '\0') {
      			return ERR_ARGS_COUNT;
      			}
                 int res = custom_pow(base, pow);    
                 if (res == ERR_ARGS_COUNT) {
                 printf("Ошибка ввода"); 
                 } else { 
                 printf("%d\n", res); 
                 } 
                 break; 
                 } 
            return ERR_ARGS_COUNT;
            break;
        case TST_MOD_IMPL: 
        if (argc == 3) {
             int num = strtol(data, &end, 10);
             if (*end != '\0') {
      		return ERR_ARGS_COUNT; 
      		}
             printf("%d", is_prime(num));
             break; 
             }
             return ERR_ARGS_COUNT;
             break;
                     
        case TST_MOD_RECURS:
        if (argc == 3) {
	     int num = (int) strtol(data, &end, 10);
	     if (*end != '\0') {
      		return ERR_ARGS_COUNT; 
      		}
	from_1_to_n(num);
	break; 
	}
	return ERR_ARGS_COUNT;
	break;
        default: {
            return ERR_WRONG_FLG; 
            } 
            }
            
}
