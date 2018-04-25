SHELL:=/bin/bash
CC:= clang
CFLAGS := -std=c11 -g -Weverything -Werror -lm

clean:
	-rm ch-*/bin/*

setup:
	mkdir -p ch-{1,2,3,4,5,6}/bin
	mkdir -p reverse-polish-calc/bin

1-4 1-5 1-6 1-7 1-8 1-9 1-10 1-11 1-12 1-13 1-15 1-16 1-17 1-18 1-19 1-20 1-21 1-23 1-24: 
	$(CC) $(CFLAGS) -I ch-1/include/ ch-1/src/$@.c -o ch-1/bin/$@
	ch-1/bin/$@

2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.10: 
	$(CC) $(CFLAGS) -I ch-2/include/ ch-2/src/$@.c -o ch-2/bin/$@
	ch-2/bin/$@

3.1 3.2 3.3 3.4 3.5 3.6:
	$(CC) $(CFLAGS) -I ch-3/include/ ch-3/src/$@.c -o ch-3/bin/$@
	ch-3/bin/$@

4.1 4.2 4.11 4.12-13 4.14:
	$(CC) $(CFLAGS) -I ch-4/include/ ch-4/src/$@.c -o ch-4/bin/$@
	ch-4/bin/$@

5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8-9 5.10 5.11 5.12 5.13 5.14 5.15 5.16 5.17 5.18 5.19 5.20:
	$(CC) $(CFLAGS) -I ch-5/include/ ch-5/src/{$@,5-common}.c -o ch-5/bin/$@
	ch-5/bin/$@

6.1 6.2 6.3 6.4 6.5 6.6:
	$(CC) $(CFLAGS) -Wno-padded -I ch-6/include/ ch-6/src/{$@,6-common}.c -o ch-6/bin/$@
	ch-6/bin/$@

rpc:
	$(CC) $(CFLAGS) -I reverse-polish-calc/include/ reverse-polish-calc/src/*.c -o reverse-polish-calc/bin/reverse-polish-calc
	./reverse-polish-calc/bin/reverse-polish-calc
