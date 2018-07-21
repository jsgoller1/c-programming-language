# Contains compile / testing settings
include ./makefiles/building.mk

# Targets for running a Dockerized testing environment
include ./makefiles/docker.mk

# Individual chapter Makefiles
include ch-1/Makefile ch-2/Makefile ch-3/Makefile ch-4/Makefile
include ch-5/Makefile ch-6/Makefile ch-7/Makefile ch-8/Makefile

### Individual exercise targets
.PHONY: ch-1 ch-2 ch-3 ch-4 ch-5 ch-6 ch-7 ch-8

all: ch-1 ch-2 ch-3 ch-4 ch-5 ch-6 ch-7 ch-8
ch-1: 1.3-4 1.5 1.6 1.7 1.8 1.9 1.10 1.11 1.12 1.13 1.14
ch-1: 1.15 1.16 1.17 1.18 1.19 1.20 1.21 1.22 1.23 1.24
ch-2: 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.10
ch-3: 3.1 3.2 3.3 3.4 3.5 3.6
ch-4: 4.1 4.2 rpc 4.11 4.12-13 4.14
ch-5: 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8-9 5.10 tabber
ch-5: tail sort decl undecl
ch-6: 6.1 charmatch crossref wordcount hashtable
ch-7: 7.1 7.2 7.3 7.4 7.5 7.6 7.7 7.8 7.9
ch-8: cat fopen_j 8.5 malloc_j
