#ifndef PROJECT_INCLUDE_TESTS_H_
#define PROJECT_INCLUDE_TESTS_H_

#include <stdio.h>
#include <string.h>


enum size {
    MAX_SIZE_FORMAT_STRING = 80,
    NAME_SIZE = 20,
    SURNAME_SIZE = 20,
    ADDRESS_SIZE = 30,
    TEL_NUMBER_SIZE = 15
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

#define client_base_filename               "client_base.dat"
#define transaction_base_filename     "transaction_base.dat"
#define update_client_base_filename "update_client_base.dat"


void write_to_file(const char *filename, data *writing_data);
void read_from_file(const char *filename, data *reading_data);

#endif  //  PROJECT_INCLUDE_TESTS_H_
