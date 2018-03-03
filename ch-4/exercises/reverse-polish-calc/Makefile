INCLUDES:= -I ./include
LIBRARIES:= -lm
SRC:= ./src/*.c
BIN:= calculator
CFLAGS:= -Wall -Werror -g -std=gnu11

all: clean calc

clean:
	-rm calculator calculator.dSYM

calc:
	gcc $(INCLUDES) $(SRC) $(LIBRARIES) $(CFLAGS) -o $(BIN) 
