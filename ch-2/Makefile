SHELL:=/bin/bash
CC:= clang
EXERCISE-FLAGS := -std=c11 -g -Weverything -Werror
EXAMPLE-FLAGS:= -std=c89

all: signed-unsigned-ints

clean:
	-rm -r bin/*

setup:
	mkdir -p bin/{examples,exercises}

# Chapter 2 examples
2.3-strlen \
2.7-atoi \
2.7-casting \
2.7-lower \
2.8-squeeze \
2.8-strcat \
2.9-getbits \
2.10-bitcount:
	$(CC) $(EXAMPLE-FLAGS) -I include/examples/ src/examples/$@.c -o bin/examples/$@
	./bin/examples/$@

# Chapter 1 exercises
2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.10:
	$(CC) $(EXERCISE-FLAGS) -I include/exercises/ src/exercises/$@.c -o bin/exercises/$@
	./bin/exercises/$@
