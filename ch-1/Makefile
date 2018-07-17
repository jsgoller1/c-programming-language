include vars.mk

1-build:
	$(COMPILE) -D TEST_OUTPUT -I ch-1/include/ ch-1/src/$$EX.c -o bin/$$EX

1.3-4 1.5 1.7 1.11 1.15 1.19: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	$(VALGRIND) ./bin/$@
endif

1.6: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "d" | $(VALGRIND) ./bin/$@
	cat EOF | $(VALGRIND) ./bin/$@
endif

1.8: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "this program prints whitespace	" | $(VALGRIND) ./bin/$@
endif

1.9: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "this   program   strips   extra   spaces" | $(VALGRIND) ./bin/$@
endif

1.10: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "this program escapes spaces and		tabs" |	$(VALGRIND) ./bin/$@
endif

1.12: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "this program prints every word in input" | $(VALGRIND) ./bin/$@
endif

1.13: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "this this this program program prints a a a a histogram" | $(VALGRIND) ./bin/$@
endif

1.14: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "this program prints a char frequency histogram" | $(VALGRIND) ./bin/$@
endif

1.16: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "this\nprogram prints\nthe longest line" | $(VALGRIND) ./bin/$@
endif

1.17: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n" | $(VALGRIND) ./bin/$@
	printf "Not longer than 80" | $(VALGRIND) ./bin/$@
endif

1.18: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "removes trailing whitespace          " | $(VALGRIND) ./bin/$@
endif

1.20: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "detabs\tlines\t" | $(VALGRIND) ./bin/$@
endif

1.21: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "tab  stops every        5 chars" | $(VALGRIND) ./bin/$@
endif

1.22:
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "01234567890123456789" | $(VALGRIND) ./bin/$@
endif

1.23:
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "// remove comments\nvoid main(){return 0;}" | $(VALGRIND) ./bin/$@
endif

1.24: clean
	make EX=$@ 1-build
ifeq ($(RUN_TESTS),true)
	printf "// remove comments\nvoid main(){return 0;}" | $(VALGRIND) ./bin/$@
	printf "// remove comments\nvoid main(){return 0;}}" | $(VALGRIND) ./bin/$@
endif
