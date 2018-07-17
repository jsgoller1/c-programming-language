### Compile
CC:=clang
CFLAGS :=-std=gnu11 -g -lm
WARNINGS :=-Weverything -Werror
INCLUDES :=-I common/include
LIBS := common/src/*.c
COMPILE:=$(ANALYZER) $(CC) $(CFLAGS) $(WARNINGS) $(INCLUDES) $(LIBS)

### Set this to true if you want to run the tests
RUN_TESTS:=false

### Uncomment this to run Clang's static analyzer while building
#ANALYZER:=scan-build

### Uncomment this to do memory leak analysis while running
#VALGRIND := valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42
