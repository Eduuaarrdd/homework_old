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
		   project/tests/include
           	
TST_SRCS = \
		   project/tests/src/main.c\
		   project/tests/src/test.c\
		   project/tests/src/write_to_file.c\
		   project/tests/src/format.c

.PHONY: all build tst rebuild check test memtest clean

all: clean check test memtest

build: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)
	
rebuild: clean build	

tst: $(TST_TARGET)
		
$(TST_TARGET): $(TST_SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_TST_DIR) -o $(TST_TARGET) $(CFLAGS) $(TST_SRCS)


rebuild: clean tst

check:
	./run_linters.sh	

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck
	   
clean:
	rm -rf $(TARGET) $(TST_TARGET) *.dat
