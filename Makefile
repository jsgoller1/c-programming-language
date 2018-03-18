SHELL:=/bin/bash
CC:= clang
FLAGS := -std=c11 -g -Weverything -Werror

all: signed-unsigned-ints

clean:
	-rm out/*/*

setup:
	mkdir -p out/ch-{1,2,3,4,5,6,7,8}/{examples,exercises,faq}

5.1-getch:
	$(CC) $(FLAGS) -I include/ch-5/ src/ch-5/examples/$@.c -o out/ch-5/examples/$@
	./out/ch-5/examples/$@

5.1 5.2:
	$(CC) $(FLAGS) -I include/ch-5/ src/ch-5/exercises/$@.c -o out/ch-5/exercises/$@
	./out/ch-5/exercises/$@
