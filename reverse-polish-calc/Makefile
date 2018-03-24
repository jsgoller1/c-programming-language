SHELL:=/bin/bash
CC:= clang
EXERCISE-FLAGS := -std=c11 -g -Weverything -Werror
EXAMPLE-FLAGS:= -std=c89

all: signed-unsigned-ints

clean:
	-rm -r bin/*

setup:
	mkdir -p bin/{examples,exercises}

# Chapter 4 examples:
4.1-grep \
4.2-atof \
4.2-atoi \
4.3-polish-calculator \
4.10-printd \
4.10-quicksort:
	$(CC) $(EXAMPLE-FLAGS) -I include/examples/ src/examples/$@.c -o bin/examples/$@
	./bin/examples/$@

# Chapter 4 exercises
4.1 4.2 4.11 4.12-13 4.14:
	$(CC) $(EXERCISE-FLAGS) -I include/exercises/ src/exercises/$@.c -o bin/exercises/$@
	./bin/exercises/$@
