SHELL:=/bin/bash
CC:= clang
EXERCISE-FLAGS := -std=c11 -g -Weverything -Werror
EXAMPLE-FLAGS:= -std=c89

all: signed-unsigned-ints

clean:
	-rm bin/*/*

setup:
	mkdir -p bin/{examples,exercises}

# Chapter 5 examples
5.2-getint \
5.3-strlen \
5.4-alloc \
5.4-strlen2 \
5.5-strcpy \
5.5-strcmp:
	$(CC) $(EXAMPLE-FLAGS) -I include/examples/ src/examples/{$@,common}.c -o bin/examples/$@
	./bin/examples/$@

5.6-sort:
	$(CC) $(EXAMPLE-FLAGS) -I include/examples/ src/examples/{$@,5.4-alloc}.c -o bin/examples/$@


# Chapter 5 exercises
5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9 5.10 5.11 5.12 5.13 5.14 5.15 5.16 5.17 5.18 5.19 5.20:
	$(CC) $(EXERCISE-FLAGS) -I include/exercises/ src/exercises/{$@,common}.c -o bin/exercises/$@
	./bin/exercises/$@
