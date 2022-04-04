#include "utils.h"



int main() {
    int choice = 0;
    int buf = 1;

    while (buf == 1) {
        menu(MAIN_MENU);
        buf = scanf("%d", &choice);

        switch (choice) {
            case    Action_write_to_client_base:
                write_to_client_base();
                break;

            case     Action_write_to_transaction_base:
                write_to_transaction_base();
                break;

            case     Action_update_client_base:
                update_client_base();
                break;

            case     Action_test_write:
                test_write();
                break;

            default:
                fprintf(stderr, input_error);
                break;
        }
    }
    return 0;
}
