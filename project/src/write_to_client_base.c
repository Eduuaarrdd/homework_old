#include "write_to_client_base.h"

void write_to_client_base() {
    data client = {0, "", "", "", "", 0, 0, 0};

    int buffer = NUMBER_OF_PARAMETERS_IN_CLIENT_BASE;

    while (buffer == NUMBER_OF_PARAMETERS_IN_CLIENT_BASE) {
        menu(Action_write_to_client_base);

        buffer = scanf("%d%19s%19s%29s%14s%lf%lf%lf", &client.id, client.name, client.surname,
            client.address, client.tel_number, &client.indebtedness,
            &client.credit_limit, &client.cash_payments);

        if (buffer != EOF)
        write_to_file(client_base_filename, &client);
    }
}
