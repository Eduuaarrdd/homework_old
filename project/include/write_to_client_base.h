#ifndef PROJECT_INCLUDE_WRITE_TO_CLIENT_BASE_H_
#define PROJECT_INCLUDE_WRITE_TO_CLIENT_BASE_H_

#include <stdio.h>

#define client_base_filename               "client_base.dat"

enum size {
    MAX_SIZE_FORMAT_STRING = 80,
    NAME_SIZE = 20,
    SURNAME_SIZE = 20,
    ADDRESS_SIZE = 30,
    TEL_NUMBER_SIZE = 15
};

enum choice {
    Action_write_to_client_base = 1,
    Action_write_to_transaction_base,
    Action_update_client_base,
    Action_test_write
};

enum numbers_for_scanf {
    NUMBER_OF_PARAMETERS_IN_CLIENT_BASE = 8,
    NUMBER_OF_PARAMETERS_IN_TRANSACTION_BASE = 2
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

void write_to_file(const char *filename, data *writing_data);
void menu(int menu_type);

#endif  //  PROJECT_INCLUDE_WRITE_TO_CLIENT_BASE_H_
