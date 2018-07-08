SHELL:=/bin/bash

ANALYZER:=scan-build
CC:=clang
CFLAGS :=-std=gnu11 -g -lm
WARNINGS :=-Weverything -Werror
INCLUDES :=-I common/include
LIBS :=common/src/*.c
COMPILE:=$(ANALYZER) $(CC) $(CFLAGS) $(WARNINGS) $(INCLUDES) $(LIBS)
VALGRIND := valgrind -q --leak-check=full --show-leak-kinds=all --error-exitcode=42

all: setup ch-1 ch-2 ch-3 ch-4 ch-5 ch-6 ch-7 ch-8

### Dockerized Linux workspace; setting up Valgrind on OSX is annoying.
docker:
	docker pull ubuntu
	docker run \
	-dt \
	--name ubuntu \
	-v `pwd`:/workspace \
	ubuntu
	docker exec ubuntu apt-get update
	docker exec ubuntu apt-get install -y make valgrind clang

shell:
	docker exec -it ubuntu /bin/bash

### Setup commands
setup:
	-mkdir bin

clean:
	-rm -r bin/*

.PHONY: rpc sort tail decl malloc_j
.PHONY: ch-%

ch-1: 1.3-4 1.5 1.6 1.7 1.8 1.9 1.10 1.11 1.12 1.13 1.14
ch-1: 1.15 1.16 1.17 1.18 1.19 1.20 1.21 1.22 1.23 1.24
ch-2: 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.10
ch-3: 3.1 3.2 3.3 3.4 3.5 3.6
ch-4: 4.1 4.2 rpc 4.11 4.12-13 4.14
ch-5: 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8-9 5.14-17 5.10 5.11
ch-5: 5.12 tail sort decl
ch-6: 6.1 charmatch crossref wordcount hashtable
ch-7: 7.1 7.2 7.3 7.4 7.5 7.6 7.7 7.8
ch-8: cat fopen_j 8.5 malloc_j

1.% 2.% 3.% 4.% 5.% 6.% 7.% 8.%: clean
	@# When making "3.4", get "3" as chapter value
	@$(eval CH := $(shell echo $@ | grep -o "[1-8]\." | sed 's/\.//' ))
	$(COMPILE) -I ch-$(CH)/include/ ch-$(CH)/src/$@.c -o bin/$@
	$(VALGRIND) ./bin/$@

## Chapter 4
# the reverse polish calc is exercises 4.3 through 4.10.
rpc: clean
	$(COMPILE) -I ch-4/rpc/include/ ch-4/rpc/src/$@.c -o bin/$@
	$(VALGRIND) ./bin/$@

## Chapter 5
# tail is exercise 5.13; I decided external tests were better than unit tests.
tail: clean
	$(COMPILE) -I ch-5/tail/include/ ch-5/tail/src/5.13.c -o bin/tail
	./tail/tail_test.sh

# sort is exercises 5.14 through 5.17
sort: clean
	$(COMPILE) -I ch-5/sort/include/ ch-5/sort/src/*.c -o bin/$@
	@if [[ -z "$(TESTS)" ]]; then \
		cat sort/sort-test.txt | $(VALGRIND) ./bin/$@; \
		else bin/$@; \
	fi

# decl/undecl is exercises 5.18 through 5.20
decl undecl: clean
	$(COMPILE) -I ch-5/decl/include/ ch-5/decl/src/*.c -o bin/$@
	$(VALGRIND) bin/$@

## Chapter 6
# charmatch is 6.2
# crossref is 6.3
# wordcount is 6.4
# hashtable is 6.5 and 6.6
crossref wordcount hashtable charmatch: clean
	$(COMPILE) -I ch-6/$@/include/ ch-6/$@/src/*.c -o bin/$@
	cat ch-6/$@/$@-test.* | $(VALGRIND) ./bin/$@

## Chapter 8
# cat is 8.1
cat: clean
	@echo "foo" > foo.test; echo "bar" > bar.test; echo "baz" > baz.test
	$(COMPILE) -I ch-8/include/ ch-8/src/8.1.c -o bin/cat
	@$(VALGRIND) ./bin/cat {foo,bar,baz}.test
	@rm *.test

# fopen (and getc) is 8.2 through 8.4
# malloc is 8.6 through 8.8
fopen_j malloc_j: clean
	$(COMPILE) -I ch-8/$@/include/ ch-8/$@/src/*.c -o bin/$@
	$(VALGRIND) ./bin/$@


