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
            printf("%s", "2 enter data transaction:\n3 update base\n4: test\n\n");
            break;

        case    CLIENT_BASE_MENU:
            printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
                "1 Number account: ",
                "2 Client name: ",
                "3 Surname: ",
                "4 Address client: ",
                "5 Client tel_number: ",
                "6 Client indebtedness: ",
                "7 Client credit limit: ",
                "8 Client cash payments: \n");
            break;

        case     TRANSACTION_BASE_MENU:
            printf("%s\n%s\n",
            "1 Number account: ",
            "2 Client cash payments: ");

        default:
            break;
    }
    return;
}
