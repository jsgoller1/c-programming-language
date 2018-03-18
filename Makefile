SHELL:=/bin/bash
CC:= clang
FLAGS := -std=c11 -g -Weverything -Werror

all: signed-unsigned-ints

clean:
	-rm bin/*/*/*

setup:
	mkdir -p bin/ch-{1,2,3,4,5,6,7,8}/{examples,exercises,faq}

# Chapter 5 examples
5.1-getch 5.3-strlen 5.4-alloc 5.4-strlen2 5.5-strcpy:
	$(CC) $(FLAGS) -I include/ch-5/ src/ch-5/examples/$@.c -o bin/ch-5/examples/$@
	./bin/ch-5/examples/$@

# Chapter 5 exercises
5.1 5.2:
	$(CC) $(FLAGS) -I include/ch-5/ src/ch-5/exercises/{$@,5-common}.c -o bin/ch-5/exercises/$@
	./bin/ch-5/exercises/$@

# Chapter 5 faq
arithmetic-ops-with-pointers:
	$(CC) $(FLAGS) src/ch-5/faq/$@.c -o bin/ch-5/faq/$@
	./bin/ch-5/faq/$@
