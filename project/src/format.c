#include "utils.h"
#include <string.h>

char* format(int format_type) {
    static char format_string[MAX_SIZE_FORMAT_STRING] = "";

    switch (format_type) {
        case  FORMAT_TO_SCANF_CLIENT_BASE:

            snprintf(format_string, MAX_SIZE_FORMAT_STRING, "%%d%%%ds%%%ds%%%ds%%%ds%%lf%%lf%%lf",
            NAME_SIZE-1, SURNAME_SIZE-1, ADDRESS_SIZE-1, TEL_NUMBER_SIZE-1);
            break;

        case FORMAT_TO_FPRINTF_CLIENT_BASE:

            snprintf(format_string, MAX_SIZE_FORMAT_STRING,
            "%%-%dd%%-%ds%%-%ds%%-%ds%%%ds%%%d.%dlf%%%d.%dlf%%%d.%dlf\n",
            ID_FORMAT, NAME_FORMAT_CLIENT_BASE, SURNAME_FORMAT, ADDRESS_FORMAT, TEL_NUMBER_FORMAT,
            INDEBTEDNESS_FORMAT_CLIENT_BASE, INDEBTEDNESS_PRECISION_CLIENT_BASE,
            INDEBTEDNESS_FORMAT_CLIENT_BASE, INDEBTEDNESS_PRECISION_CLIENT_BASE,
            INDEBTEDNESS_FORMAT_CLIENT_BASE, INDEBTEDNESS_PRECISION_CLIENT_BASE);
            break;

        case FORMAT_TO_FPRINTF_TRANSACTION_BASE:

            snprintf(format_string, MAX_SIZE_FORMAT_STRING, "%%-%dd%%-%d.%dlf\n",
            NAME_FORMAT_TRANSACTION_BASE, INDEBTEDNESS_FORMAT_TRANSACTION_BASE,
            INDEBTEDNESS_PRECISION_TRANSACTION_BASE);

        default:
           break;
    }
    return format_string;
}
