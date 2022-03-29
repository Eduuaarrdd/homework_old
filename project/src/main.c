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


/* NOTE(stitaevskiy):
 * We use `atoi` function just for simplification and code reducing.
 * This function doesn't report conversation errors.
 * For safety program we recommend using `strtol` and its analogs.
 * (See `man atoi` and `man strtol` for more info).
 *
 * const char str_num[] = "1234";
 * char* end = NULL;
 * int val = (int) strtol(str_num, &end, 0);
 * if (end != '\0') {
 *     //ERROR
 * }
 *
 * */

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
        case TST_FOO_FIX: {
            int to = strtol(data, &end, 10);
            if (*end != '\0') {
      return ERR_ARGS_COUNT;
  }
            size_t ticks_count = timer_from(to);
            printf("%zu", ticks_count);
            break;
        }
        case TST_FOO_IMPL: {
            if (argc == 4) {
                 int base = strtol(data, &end, 10);
                 if (*end != '\0') {
      return ERR_ARGS_COUNT;
  }
                 int pow =  strtol(argv[3], &end, 10);
                 if (*end != '\0') {
      return ERR_ARGS_COUNT;
  }
                 int res = custom_pow(base, pow);    // TODO(Eduard): Implement me
                 printf("%i\n", res);
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }
        case TST_MOD_IMPL: {
             int num = strtol(data, &end, 10);
             if (*end != '\0') {
      return ERR_ARGS_COUNT;
  }
             int resul = is_prime(num);
             printf("%d", resul);
             break;

            // TODO(Eduard): Print to stdout `1` if `num` is prime number and `0` otherwise
            // This function MUST be implemented in
            // a separate C-module (not in `main` or `utils` module)
        }
        case TST_MOD_RECURS: {
	     int num = (int) strtol(data, &end, 10);
	     if (*end != '\0') {
      return ERR_ARGS_COUNT;
  }
	printf("%c", from_1_to_n(num));
	     break;
	    }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}
