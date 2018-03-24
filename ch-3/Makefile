SHELL:=/bin/bash
CC:= clang
EXERCISE-FLAGS := -std=c11 -g -Weverything -Werror
EXAMPLE-FLAGS:= -std=c89

all: signed-unsigned-ints

clean:
	-rm -r bin/*

setup:
	mkdir -p bin/{examples,exercises}

# Chapter 3 examples:
3.3-binsearch \
3.4-char-count \
3.5-atoi \
3.6-itoa \
3.6-reverse \
3.6-shellsort \
3.7-trim:
	$(CC) $(EXAMPLE-FLAGS) -I include/examples/ src/examples/$@.c -o bin/examples/$@
	./bin/examples/$@

# Chapter 3 exercises
3.1 \
3.2 \
3.3 \
3.4 \
3.5 \
3.6:
	$(CC) $(EXERCISE-FLAGS) -I include/exercises/ src/exercises/$@.c -o bin/exercises/$@
	./bin/exercises/$@
