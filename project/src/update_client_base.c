#include "update_client_base.h"

void update_client_base() {
    data transfer = {0, "", "", "", "", 0, 0, 0};
    data client_data = {0, "", "", "", "", 0, 0, 0};


    FILE *client_base_file = fopen(client_base_filename, "r");
    FILE *transaction_base_file = fopen(transaction_base_filename, "r");
    FILE *update_client_base_file = fopen(update_client_base_filename, "w");


    if (!client_base_file || !transaction_base_file || !update_client_base_file) {
        fprintf(stderr, access_error);
    } else {
        while (fscanf(client_base_file, format(FORMAT_TO_SCANF_CLIENT_BASE), &client_data.id,
                    client_data.name, client_data.surname, client_data.address,
                    client_data.tel_number, &client_data.indebtedness,
                    &client_data.credit_limit,
                    &client_data.cash_payments) == NUMBER_OF_PARAMETERS_IN_CLIENT_BASE) {
            while (fscanf(transaction_base_file, "%d %lf", &transfer.id, &transfer.cash_payments) != -1) {
                if (client_data.id == transfer.id && transfer.cash_payments) {
                    client_data.credit_limit += transfer.cash_payments;
                }
            }
            fprintf(update_client_base_file, format(FORMAT_TO_FPRINTF_CLIENT_BASE), client_data.id,
                    client_data.name, client_data.surname, client_data.address, client_data.tel_number,
                    client_data.indebtedness, client_data.credit_limit, client_data.cash_payments);
            rewind(transaction_base_file);
        }
        fclose(client_base_file);
        fclose(transaction_base_file);
        fclose(update_client_base_file);
}
