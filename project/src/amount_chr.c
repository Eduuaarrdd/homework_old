#include <amount_chr.h>

int amount_chr (char *end, int length) {
	end = end + length;
	for (int i = 0; *end; ++i) {
		if (*end != '/n') {
			//str_fr[i] = data* 
			++end;
		} else { 
			if (isspace(*(++end))) {
				//str_fr[++i] = ' '
				return i;
				break;
			}
			}
	}
	return -1;
}
				
		
