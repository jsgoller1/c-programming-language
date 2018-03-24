SHELL:=/bin/bash
CC:= clang
EXERCISE-FLAGS := -std=c11 -g -Weverything -Werror
EXAMPLE-FLAGS:= -std=c89

all: signed-unsigned-ints

clean:
	-rm -r bin/*

setup:
	mkdir -p bin/{examples,exercises}

# Chapter 1 examples
1.1-hello-world \
1.10-print-longest-line-externs \
1.2-fahrenheit-to-celsius-floats \
1.2-fahrenheit-to-celsius \
1.3-for-temp-converter \
1.4-temp-converter-constants \
1.5.1-input-copier-simpler \
1.5.1-input-copier \
1.5.2-character-count-2 \
1.5.2-character-count \
1.5.3-line-count \
1.5.4-word-count \
1.6-arrays-digits-whitespace \
1.7-exponentiation-by-value \
1.7-exponentiation \
1.9-print-longest-line:
	$(CC) $(EXAMPLE-FLAGS) -I include/examples/ src/examples/$@.c -o bin/examples/$@
	./bin/examples/$@

# Chapter 1 exercises
1-4 1-5 1-6 1-7 1-8 1-9 1-10 1-11 1-12 1-13 1-15 1-16 1-17 1-18 1-19 1-20 1-21 1-23 1-24.c:
	$(CC) $(EXERCISE-FLAGS) -I include/exercises/ src/exercises/$@.c -o bin/exercises/$@
	./bin/exercises/$@
