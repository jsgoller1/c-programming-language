4.1: 4.1-build 4.1-basic-test

4.2: 4.2-build
ifdef RUN_TESTS
	printf "10.0e4" | $(VALGRIND) ./bin/$@
	printf "10.0e-4" | $(VALGRIND) ./bin/$@
	echo -10.0e4 | $(VALGRIND) ./bin/$@
	echo -10.0e-4 | $(VALGRIND) ./bin/$@
	printf "" | $(VALGRIND) ./bin/$@
endif

# the reverse polish calc is exercises 4.3 through 4.10.
rpc: clean
	$(COMPILE) -I ch-4/rpc/include/ ch-4/rpc/src/*.c -o bin/$@
ifdef RUN_TESTS
	printf "4 5 +\n" | $(VALGRIND) ./bin/$@
	@#printf "4 5 + 5 6 + -\n" | $(VALGRIND) ./bin/$@
	@#printf "5 SIN" | $(VALGRIND) ./bin/$@
	@#printf "b 6 = \n b 10 *\n" | $(VALGRIND) ./bin/$@
	@#printf "" | $(VALGRIND) ./bin/$@
endif

4.11: 4.11-build
ifdef RUN_TESTS
	printf "20 5 +\n" | $(VALGRIND) ./bin/$@
	printf "20 5 5 + +\n" | $(VALGRIND) ./bin/$@
	printf "" | $(VALGRIND) ./bin/$@
endif

4.12-13: 4.12-13-build 4.12-13-basic-test
4.14: 4.14-build 4.14-basic-test
