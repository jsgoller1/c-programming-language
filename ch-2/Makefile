include vars.mk

# "build" is in the top-level makefile
2.1 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.10: clean
	make EX=$@ CH=ch-2 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@
endif

2.2:
	make EX=$@ CH=ch-2 build
ifdef RUN_TESTS
	printf "this line is 26 chars long" | $(VALGRIND) ./bin/$@
	printf "" | $(VALGRIND) ./bin/$@
endif
