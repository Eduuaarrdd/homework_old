TARGET = ./main.out
HDRS_DIR = project/include

SRCS = \
project/src/main.c\
project/src/write_to_client_base.c\
project/src/write_to_file.c\
project/src/menu.c\
project/src/test.c\
project/src/format.c\
project/src/write_to_transaction_base.c\
project/src/update_client_base.c

.PHONY: all build rebuild check test memtest clean

all: clean check test memtest

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

check:
	./run_linters.sh

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

clean:
	rm -rf $(TARGET) *.dat
