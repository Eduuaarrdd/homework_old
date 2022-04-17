#include <stdio.h>

enum menu {
    MAIN_MENU,
    CLIENT_BASE_MENU,
    TRANSACTION_BASE_MENU
};


void menu(int menu_type) {
    switch (menu_type) {
        case    MAIN_MENU:
            printf("%s", "Please enter action\n1 enter data client:\n");
            printf("%s", "2 enter data transaction:\n3 update base\n\n");
            break;

        case    CLIENT_BASE_MENU:
            printf("1 Number account:\n2 Client name:\n3 Surname:\n4 Address client:\n5 Client tel_number:");
            printf("\n6 Client indebtedness:\n7 Client credit limit:\n8 Client cash payments:\n");
            break;

        case     TRANSACTION_BASE_MENU:
            printf("1 Number account:\n2 Client cash payments:\n");

        default:
            break;
    }
    return;
}
