### Uncomment this to run Clang's static analyzer while building; this makes the build slower.
ANALYZER:=scan-build --status-bugs

### Compiler settings
CC:=clang
CFLAGS :=-std=gnu11 -g -lm
WARNINGS :=-Weverything -Werror
INCLUDES :=-I common/include
LIBS := common/src/*.c
EXTRA_FLAGS:=-D TEST_OUTPUT
COMPILE:=$(ANALYZER) $(CC) $(CFLAGS) $(WARNINGS) $(EXTRA_FLAGS) $(INCLUDES) $(LIBS)

### Uncomment this if you want to run the tests; this makes the build slower.
RUN_TESTS:=true

### Uncomment this to do memory leak analysis while running; this makes tests run (slightly) slower
VALGRIND := valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42

# Each individual make target runs a build target
# matching to this to produce the compiled binary.
%-build: clean
	$(eval CHAPTER := ch-$(shell echo $@ | sed -E 's/\.([0-9]*|[0-9]*-[0-9]*)-build//g'))
	$(eval EXERCISE := $(shell echo $@ | sed 's/-build//'))
	$(COMPILE) -I $(CHAPTER)/include $(CHAPTER)/src/$(EXERCISE).c -o bin/$(EXERCISE)

### Exercises that do not need any input for testing can use this target for testing;
### otherwise, they will run tests their own way.
%-basic-test:
ifdef RUN_TESTS
	$(eval EXERCISE := $(shell echo $@ | sed 's/-basic-test//'))
	$(VALGRIND) ./bin/$(EXERCISE)
endif

### Binary cleanup
setup:
	-mkdir bin

clean:
	-rm -r bin/*
