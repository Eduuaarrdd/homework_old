#include "utils.h"

void write_to_file(const char *filename, data *writing_data) {
    if (!strcmp(filename, client_base_filename)) {
        FILE *client_base_file = fopen(filename, "a+");

        if (!client_base_file) {
            fprintf(stderr, access_error);
        } else {
            fprintf(client_base_file, format(FORMAT_TO_FPRINTF_CLIENT_BASE),
                (*writing_data).id, (*writing_data).name, (*writing_data).surname,
                (*writing_data).address, (*writing_data).tel_number, (*writing_data).indebtedness,
                (*writing_data).credit_limit, (*writing_data).cash_payments);

            fclose(client_base_file);
        }
    }

    if (!strcmp(filename, transaction_base_filename)) {
        FILE *transaction_data_file = fopen(filename, "a+");

        if (!transaction_data_file) {
            fprintf(stderr, access_error);
        } else {
            fprintf(transaction_data_file, format(FORMAT_TO_FPRINTF_TRANSACTION_BASE),
                (*writing_data).id, (*writing_data).cash_payments);

            fclose(transaction_data_file);
        }
    }
}

void read_from_file(const char *filename, data *reading_data) {
    if (!strcmp(filename, client_base_filename)) {
        FILE *client_base_file = fopen(filename, "r");

        if (client_base_file == NULL) {
            fprintf(stderr, access_error);
        } else {
            fscanf(client_base_file, format(FORMAT_TO_SCANF_CLIENT_BASE),
                &(*reading_data).id, (*reading_data).name,
                (*reading_data).surname, (*reading_data).address,
                (*reading_data).tel_number, &(*reading_data).indebtedness,
                &(*reading_data).credit_limit, &(*reading_data).cash_payments);

            fclose(client_base_file);
        }
    }

    if (!strcmp(filename, transaction_base_filename)) {
        FILE *transaction_data_file = fopen(filename, "r");

        if (!transaction_data_file) {
            fprintf(stderr, access_error);
        } else {
            fscanf(transaction_data_file, "%d%lf", &(*reading_data).id, &(*reading_data).cash_payments);

            fclose(transaction_data_file);
        }
    }
}

/*  "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n"

"%-3d%-6.2lf\n"

"%d%19s%19s%29s%14s%lf%lf%lf"  */

