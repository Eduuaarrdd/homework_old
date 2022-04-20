#ifndef PROJECT_INCLUDE_EXTRACT_STR_H_
#define PROJECT_INCLUDE_EXTRACT_STR_H_

#include <stdio.h>

#define LENGTH_FROM 5;
#define LENGTH_TO 3;
#define LENGTH_DATE 5;

#define END -3

typedef enum {
	L_FROM,
	L_TO,
	L_DATE,
	L_END
} lexem_t; 

typedef enum {
	S_BEGIN,
	S_FROM,
	S_TO,
	S_DATE,
	S_END,
	S_ERR
} state_t

typedef int (*action_t) (char *end, int length);  

typedef struct {
    state_t state;
    action_t action;
} rule_t;



rule_t transitions[S_END][L_END] = { 
			// L_FROM			L_TO				L_DATE				L_END		
/* S_BEGIN */		{{S_FROM, amount_chr},		{S_ERR, NULL}, 		{S_ERR, NULL},			{S_END, NULL}}, 
/* S_FROM */		{{S_ERR, NULL},		{S_TO, amount_chr}, 		{S_ERR, NULL},			{S_END, END}},
/* S_TO */		{{S_ERR, NULL},		{S_ERR, NULL}, 		{S_DATE, amount_chr},		{S_END, END}},
/* S_DATE */		{{S_ERR, NULL},		{S_ERR, NULL}, 		{S_ERR, NULL},			{S_END, END}},
/* S_END */		{{S_ERR, NULL},		{S_ERR, NULL}, 		{S_ERR, NULL},			{S_ERR, NULL}}
};
			
int amount_chr (char *end, int length);
lexem_t get_lexem(char* data)

#endif  //  PROJECT_INCLUDE_EXTRACT_STR_H_
