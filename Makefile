SHELL:=/bin/bash
CC:= clang
CFLAGS := -std=c11 -g -Weverything -Werror -lm
CMOCKA := -l cmocka -L/usr/lib/libcmocka.so.0.4.1

all: setup ch-1 ch-2 ch-3 ch-4 ch-5 ch-6 ch-7 ch-8

setup:
	-mkdir bin

cmocka-test:
	$(CC) $(CFLAGS) -l cmocka -L/usr/lib/libcmocka.so.0.4.1 $@.c -o bin/$@
	bin/$@

ch-1: 1.3-4 1.5 1.6 1.7 1.8 1.9 1.10 1.11 1.12 1.13 1.14
ch-1: 1.15 1.16 1.17 1.18 1.19 1.20 1.21 1.22 1.23 1.24
1.%:
	$(CC) $(CFLAGS) -I ch-1/include/ ch-1/src/{$@,common}.c -o bin/$@

ch-2: 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.10
2.%:
	$(CC) $(CFLAGS) -I ch-2/include/ ch-2/src/{$@,common}.c -o bin/$@

ch-3: 3.1 3.2 3.3 3.4 3.5 3.6
3.%:
	$(CC) $(CFLAGS) $(CMOCKA) -I ch-3/include/ ch-3/src/$@.c -o bin/$@
	bin/$@

ch-4: 4.1 4.2 4.11 4.12-13 4.14 rpc
4.%:
	$(CC) $(CFLAGS) -I ch-4/include/ ch-4/src/$@.c -o bin/$@

rpc:
	$(CC) $(CFLAGS) -I reverse-polish-calc/include/ reverse-polish-calc/src/*.c -o bin/reverse-polish-calc

ch-5: 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8-9 5.10 5.11
ch-5: 5.12 5.13 5.14 5.15 5.16 5.17 5.18 5.19 5.20
5.%:
	$(CC) $(CFLAGS) -I ch-5/include/ ch-5/src/{$@,5-common}.c -o bin/$@

ch-6: 6.1 6.2 6.3 6.4 6.5 6.6
6.%:
	$(CC) $(CFLAGS) -Wno-padded -I ch-6/include/ ch-6/src/{$@,6-common}.c -o bin/$@

ch-7: 7.1 7.2 7.3 7.4 7.5 7.6 7.7 7.8
7.%:
	$(CC) $(CFLAGS) -Wno-padded -I ch-7/include/ ch-7/src/{$@,7-common}.c -o bin/$@

ch-8: 8.1 8.2 8.3 8.4 8.5 8.6 8.8 8.8
8.%:
	$(CC) $(CFLAGS) -Wno-padded -I ch-8/include/ ch-8/src/{$@,8-common}.c -o bin/$@

clean:
	-rm -r bin/*
