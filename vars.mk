### Compile
CC:=clang
CFLAGS :=-std=gnu11 -g -lm
WARNINGS :=-Weverything -Werror
INCLUDES :=-I common/include
LIBS := common/src/*.c
EXTRA_FLAGS:=-D TEST_OUTPUT
COMPILE:=$(ANALYZER) $(CC) $(CFLAGS) $(WARNINGS) $(EXTRA_FLAGS) $(INCLUDES) $(LIBS)

### Uncomment this if you want to run the tests
RUN_TESTS:=true

### Uncomment this to run Clang's static analyzer while building
#ANALYZER:=scan-build

### Uncomment this to do memory leak analysis while running
VALGRIND := valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42
