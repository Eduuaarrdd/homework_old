#include "utils.h"

void write_to_transaction_base() {
    data transaction = {0, "", "", "", "", 0, 0, 0};

    int buffer = NUMBER_OF_PARAMETERS_IN_TRANSACTION_BASE;

    while (buffer == NUMBER_OF_PARAMETERS_IN_TRANSACTION_BASE) {
        menu(Action_write_to_transaction_base);

        buffer = scanf("%d %lf", &transaction.id, &transaction.cash_payments);

        if (buffer != EOF)
        write_to_file(transaction_base_filename, &transaction);
    }
}
