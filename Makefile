SHELL:=/bin/bash
CC:=clang
CFLAGS :=-std=c11 -g -Weverything -Werror -lm
#DEBUG:=-D DEBUG
#TEST_MESSAGES:=-D TEST_MESSAGES
OUTPUT_LEVEL:= $(DEBUG) $(TEST_MESSAGES)
TESTS := $(OUTPUT_LEVEL) -I tests/include tests/src/tests.c

all: setup ch-1 ch-2 ch-3 ch-4 rpc ch-5 ch-6 ch-7 ch-8

setup:
	-mkdir bin

clean:
	-rm -r bin/*

ch-1: 1.3-4 1.5 1.6 1.7 1.8 1.9 1.10 1.11 1.12 1.13 1.14
ch-1: 1.15 1.16 1.17 1.18 1.19 1.20 1.21 1.22 1.23 1.24
ch-2: 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.10
ch-3: 3.1 3.2 3.3 3.4 3.5 3.6
ch-4: 4.1 4.2 4.11 4.12-13 4.14 
ch-5: 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8-9 5.10 5.11
ch-5: 5.12 5.13 5.14 5.15 5.16 5.17 5.18 5.19 5.20
ch-6: 6.1 6.2 6.3 6.4 6.5 6.6
ch-7: 7.1 7.2 7.3 7.4 7.5 7.6 7.7 7.8
ch-8: 8.1 8.2 8.3 8.4 8.5 8.6 8.8 8.8

1.% 2.% 3.% 4.% 5.% 6.% 7.% 8.%:
	@# When making "3.4", get "3" as chapter value
	@$(eval CH := $(shell echo $@ | grep -o "[1-8]\." | sed 's/\.//' ))
	$(CC) $(CFLAGS) -I ch-$(CH)/include/ $(TESTS)  ch-$(CH)/src/{$@,common}.c -o bin/$@
	bin/$@

#rpc:
#	$(CC) $(CFLAGS) -I reverse-polish-calc/include/ $(TESTS)  reverse-polish-calc/src/{$@,common}.c -o bin/$@
