#include <get_lexem.h>

lexem_t get_lexem(char* data) {
	lexem_t lexem;
	char* str_from = "FROM:";
	char* str_to = "TO:";
	char* str_date = "DATE:";
		if ((strstr(*data, *str_from)) != NULL) {
			data = strstr(*data, *str_from);
			return L_FROM;
		}
		if ((strstr(*data, *str_to)) != NULL) {
			data = strstr(*data, *str_to);
			return L_TO;
		}
		if ((strstr(*data, *str_date)) != NULL) {
			data = strstr(*data, *str_date);
			return L_DATE;
		}
	return L_END; 
	}
			
	
	
