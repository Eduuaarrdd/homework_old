#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum size {
    MAX_SIZE_FORMAT_STRING = 80,
    NAME_SIZE = 20,
    SURNAME_SIZE = 20,
    ADDRESS_SIZE = 30,
    TEL_NUMBER_SIZE = 15
};

enum numbers_for_scanf {
    NUMBER_OF_PARAMETERS_IN_CLIENT_BASE = 8,
    NUMBER_OF_PARAMETERS_IN_TRANSACTION_BASE = 2
};

enum format_of_write_to_file {
    ID_FORMAT = 12,
    NAME_FORMAT_CLIENT_BASE = 11,
    NAME_FORMAT_TRANSACTION_BASE = 3,
    SURNAME_FORMAT = 11,
    ADDRESS_FORMAT = 16,
    TEL_NUMBER_FORMAT = 20,
    INDEBTEDNESS_FORMAT_CLIENT_BASE = 12,
    INDEBTEDNESS_PRECISION_CLIENT_BASE = 2,
    INDEBTEDNESS_FORMAT_TRANSACTION_BASE = 6,
    INDEBTEDNESS_PRECISION_TRANSACTION_BASE = 2
};


enum format {
FORMAT_TO_SCANF_CLIENT_BASE,
FORMAT_TO_FPRINTF_CLIENT_BASE,
FORMAT_TO_FPRINTF_TRANSACTION_BASE
};

enum menu {
    MAIN_MENU,
    CLIENT_BASE_MENU,
    TRANSACTION_BASE_MENU
};

enum choice {
    Action_write_to_client_base = 1,
    Action_write_to_transaction_base,
    Action_update_client_base,
    Action_test_write
};

#define client_base_filename               "client_base.dat"
#define transaction_base_filename     "transaction_base.dat"
#define update_client_base_filename "update_client_base.dat"


#define input_error  "INPUT ERROR"
#define access_error  "NO ACCESS"


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

void write_to_client_base();
void write_to_transaction_base();
void update_client_base();
void test_write();
void menu(int menu_type);
void write_to_file(const char *filename, data *writing_data);
void read_from_file(const char *filename, data *reading_data);
char* format(int format_type);




#endif  //  PROJECT_INCLUDE_UTILS_H_
