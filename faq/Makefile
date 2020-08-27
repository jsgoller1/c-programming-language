SHELL:=/bin/bash
CC:= clang
FLAGS := -std=c11 -g -Weverything -Werror
VALGRIND := valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42

### Dockerized Linux workspace for consistent environment
docker-clean:
	-docker stop ubuntu
	-docker rm ubuntu

docker: docker-clean
	docker pull ubuntu
	docker run \
	-dt \
	--name ubuntu \
	-v `pwd`:/c-faq \
	ubuntu
	docker exec ubuntu apt-get update
	docker exec ubuntu apt-get install -y make valgrind clang clang-tools cdecl perl

shell:
	docker exec -it ubuntu /bin/bash

workspace: docker-clean docker shell

clean:
	-rm bin/*

setup:
	-mkdir bin

# Chapter 5 examples
arithmetic-ops-with-pointers \
arrays-of-arrays \
assign-to-assignment \
fucking-for-loops \
initialization \
initializing-string-literals \
long-lines \
negative-integers \
null-terminators \
print-empty-arrays \
printing-signed \
returning-structs \
single-quotes \
strcmp \
struct-alignment-bits \
type-sizes \
typedef-struct\
unsigned-overflow: setup
	$(CC) $(FLAGS) $@.c -o bin/$@
	./bin/$@
