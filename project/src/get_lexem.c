#include <get_lexem.h>

lexem_t get_lexem(char* data) {
	lexem_t lexem;
		if (strstr(*data, "L_FROM")) {
		data = &strstr(*data, "L_FROM");
		lexem = L_FROM;
		}
		if (strstr(*data, "L_TO")) {
		data = &strstr(*data, "L_TO");
		lexem = L_TO;
		}
		if (strstr(*data, "L_DATE")) {
		data = &strstr(*data, "L_DATE");
		lexem = L_DATE;
		}
	lexem = L_END;
	return lexem; 
	}
			
	
	
