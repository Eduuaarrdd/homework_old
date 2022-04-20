TARGET = ./main.out
HDRS_DIR = project/include
VALGRIND_LOG = "valgrind.log"

SRCS = \
	   project/src/main.c \
	   project/src/get_lexem.c \
	   project/src/extract_str.c \
	   project/src/amount_chr.c

.PHONY: all check build test memtest rebuild clean

all: clean check build test memtest

check:
	./run_linters.sh

build: $(TARGET)

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

rebuild: clean build

# $(TARGET): $(SRCS)
#	$(CC) -Wall -Wextra -Werror $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS)

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

clean:
	rm -f $(TARGET) ${VALGRIND_LOG}
