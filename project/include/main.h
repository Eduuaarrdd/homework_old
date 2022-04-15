#ifndef PROJECT_INCLUDE_MAIN_H_
#define PROJECT_INCLUDE_MAIN_H_

#define input_error  "INPUT ERROR"

#include <stdio.h>

enum menu {
    MAIN_MENU,
    CLIENT_BASE_MENU,
    TRANSACTION_BASE_MENU
};

enum choice {
    Action_write_to_client_base = 1,
    Action_write_to_transaction_base,
    Action_update_client_base,
};

void write_to_client_base();
void write_to_transaction_base();
void update_client_base();
void menu(int menu_type);

#endif  //  PROJECT_INCLUDE_MAIN_H_
