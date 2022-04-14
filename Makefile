TARGET = ./main.out
HDRS_DIR = project/include
VALGRIND_LOG = "valgrind.log"

# Main

HDRS = \
	   project/include \

SRCS = \
	project/src/main.c\
	project/src/write_to_client_base.c\
	project/src/write_to_file.c\
	project/src/menu.c\
	project/src/format.c\
	project/src/write_to_transaction_base.c\
	project/src/update_client_base.c

# Test
TST_TARGET = ./test.out

HDRS_TST_DIR = project/tests/include

TST_HDRS = \
           project/include \
		   project/tests/include
           	
TST_SRCS = \
		   project/src/write_to_file.c \
		   	project/tests/src/*.c

.PHONY: all build rebuild check test memtest clean

all: clean check test memtest

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

$(TST_TARGET): $(TST_SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_TST_DIR) -o $(TST_TARGET) $(CFLAGS) $(TST_SRCS)

build: $(TST_TARGET)

rebuild: clean build

check:
	./run_linters.sh	

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck
	   
clean:
	rm -rf $(TARGET) $(TST_TARGET) *.dat
