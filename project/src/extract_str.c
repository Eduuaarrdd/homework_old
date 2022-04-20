#include <extract_str.h>

void extract_str(char *date) {

	state_t state = S_BEGIN;
	char str_out[MAX_SIZE];
	int old_amount = 0;
	lexem_t lexem = get_lexem(*data);
	while (lexem != L_END) {
		switch (state) {
			case (S_FROM): length = LENGTH_FROM;
			case (S_TO): length = LENGTH_TO;
			case (S_DATE): length = LENGTH_DATE;
			case (S_END): return;
		} 
		char* end = *data;
		end = data;
		rule_t rule = transitions[state][lexem];
			if (rule.state == S_ERR) {
				printf("ERROR");
				return;
			}
			if (rule.state == S_END) {
				return;
			}
		int amount = rule.action;
		old_amount = old_amount + amount;
		while (old_amount >= 0) {
			str_out [old_amount] = '|'
			str_out [--old_amount] = *(--end); 
		}
		lexem = get_lexem(*data);
	}
	str_out [++old_amount] = '\n';	
	printf("%s", str_out);
}		

