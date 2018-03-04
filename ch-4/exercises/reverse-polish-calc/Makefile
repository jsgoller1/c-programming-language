INCLUDES:= -I ./include
LIBRARIES:= -lm
CC:= clang
SRC:= ./src/*.c
BIN:= calculator
CFLAGS:= -Wall -Werror -g -std=gnu11

all: clean calc

clean:
	-@rm -r calculator.dSYM calculator

calc:
	$(CC) $(INCLUDES) $(SRC) $(LIBRARIES) $(CFLAGS) -o $(BIN)
