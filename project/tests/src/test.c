#include "tests.h"


void test_write() {
    data expected_data = {1, "Lera", "Veselova", "Moscow", "8968840111", 100, 180, 15};

    FILE *client_base_file = fopen(client_base_filename, "w");

        if (!client_base_file) {
            puts("Not access");
            return;
        } else {
            fclose(client_base_file);  // если файл не закрыть, то дальнейшая функция не будет работать
        }
    write_to_file(client_base_filename, &expected_data);

    data got_data = {0};

    read_from_file(client_base_filename, &got_data);

    if (expected_data.id == got_data.id) {
      if (!strcmp(expected_data.name, got_data.name)) {
        if (!strcmp(expected_data.surname, got_data.surname)) {
          if (!strcmp(expected_data.address, got_data.address)) {
            if (!strcmp(expected_data.tel_number, got_data.tel_number)) {
              if (expected_data.indebtedness == got_data.indebtedness) {
                if (expected_data.cash_payments == got_data.cash_payments) {
                  if (expected_data.credit_limit == got_data.credit_limit) {
                      puts("Test_write success");
                  }
                }
              }
            }
          }
        }
      }
    } else {
      puts("Test_write failed");
    }
    return;
}
