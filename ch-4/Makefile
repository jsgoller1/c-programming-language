include vars.mk

# "build" is in the top-level makefile
4.1 4.12-13 4.14: clean
	make EX=$@ CH=ch-4 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@
endif

4.2:
	make EX=$@ CH=ch-4 build
ifdef RUN_TESTS
	printf "10.0e4" | $(VALGRIND) ./bin/$@
	printf "10.0e-4" | $(VALGRIND) ./bin/$@
	echo -10.0e4 | $(VALGRIND) ./bin/$@
	echo -10.0e-4 | $(VALGRIND) ./bin/$@
	printf "" | $(VALGRIND) ./bin/$@
endif

4.11:
	make EX=$@ CH=ch-4 build
ifdef RUN_TESTS
	printf "20 5 +\n" | $(VALGRIND) ./bin/$@
	printf "20 5 5 + +\n" | $(VALGRIND) ./bin/$@
	printf "" | $(VALGRIND) ./bin/$@
endif

## Chapter 4
# the reverse polish calc is exercises 4.3 through 4.10.
rpc: clean
	$(COMPILE) -I ch-4/rpc/include/ ch-4/rpc/src/$@.c -o bin/$@
	$(VALGRIND) ./bin/$@
