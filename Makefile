# See vars.mk for compile / testing settings
include vars.mk
include ch-1/Makefile ch-2/Makefile ch-3/Makefile

### Binaries
setup:
	-mkdir bin

clean:
	-rm -r bin/*

### Dockerized Linux workspace; setting up Valgrind on OSX is annoying.
docker-clean:
	-docker stop ubuntu
	-docker rm ubuntu

docker: docker-clean
	docker pull ubuntu
	docker run \
	-dt \
	--name ubuntu \
	-v `pwd`:/k-and-r \
	ubuntu
	docker exec ubuntu apt-get update
	docker exec ubuntu apt-get install -y make valgrind clang clang-tools cdecl perl

shell:
	docker exec -it ubuntu /bin/bash

workspace: docker-clean docker shell

### Build targets
.PHONY: ch-1 ch-2 ch-3 ch-4 ch-5 ch-6 ch-7 ch-8

all: setup ch-1 ch-2 ch-3 ch-4 ch-5 ch-6 ch-7 ch-8

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

# Each individual make target runs the build target to produce
# the compiled binary. I didn't want to have to redefine this
# target individually for each chapter makefile but I couldn't
# find a way to pass variables to make targets without recursive
# making - see: https://stackoverflow.com/questions/14880419/share-variables-between-makefiles
build:
	$(COMPILE) -I $$CH/include $$CH/src/$$EX.c -o bin/$$EX

