#ifndef PROJECT_INCLUDE_UPDATE_CLIENT_BASE_H_
#define PROJECT_INCLUDE_UPDATE_CLIENT_BASE_H_

#include <stdio.h>

#define access_error  "NO ACCESS"

#define client_base_filename          "client_base.dat"
#define transaction_base_filename     "transaction_base.dat"
#define update_client_base_filename   "update_client_base.dat"

enum numbers_for_scanf {
    NUMBER_OF_PARAMETERS_IN_CLIENT_BASE = 8,
    NUMBER_OF_PARAMETERS_IN_TRANSACTION_BASE = 2
};

enum size {
    MAX_SIZE_FORMAT_STRING = 80,
    NAME_SIZE = 20,
    SURNAME_SIZE = 20,
    ADDRESS_SIZE = 30,
    TEL_NUMBER_SIZE = 15
};

enum format {
FORMAT_TO_SCANF_CLIENT_BASE,
FORMAT_TO_FPRINTF_CLIENT_BASE,
FORMAT_TO_FPRINTF_TRANSACTION_BASE
};

struct user_data {
  int id;
  char name[NAME_SIZE];
  char surname[SURNAME_SIZE];
  char address[ADDRESS_SIZE];
  char tel_number[TEL_NUMBER_SIZE];
  double indebtedness;
  double credit_limit;
  double cash_payments;
};

typedef  struct  user_data data;


char* format(int format_type);

#endif  //  PROJECT_INCLUDE_UPDATE_CLIENT_BASE_H_
