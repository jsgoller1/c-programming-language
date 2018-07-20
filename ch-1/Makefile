1.3-4: 1.3-4-build 1.3-4-basic-test

1.5: 1.5-build 1.5-basic-test

1.6: 1.6-build
ifdef RUN_TESTS
	printf "d" | $(VALGRIND) ./bin/$@
	cat EOF | $(VALGRIND) ./bin/$@
endif

1.7: 1.7-build 1.7-basic-test

1.8: 1.8-build
ifdef RUN_TESTS
	printf "this program prints whitespace	" | $(VALGRIND) ./bin/$@
endif

1.9: 1.9-build
ifdef RUN_TESTS
	printf "this   program   strips   extra   spaces" | $(VALGRIND) ./bin/$@
endif

1.10: 1.10-build
ifdef RUN_TESTS
	printf "this program escapes spaces and		tabs" |	$(VALGRIND) ./bin/$@
endif

1.11: 1.11-build 1.11-basic-test

1.12: 1.12-build
ifdef RUN_TESTS
	printf "this program prints every word in input" | $(VALGRIND) ./bin/$@
endif

1.13: 1.13-build
ifdef RUN_TESTS
	printf "this this this program program prints a a a a histogram" | $(VALGRIND) ./bin/$@
endif

1.14: 1.14-build
ifdef RUN_TESTS
	printf "this program prints a char frequency histogram" | $(VALGRIND) ./bin/$@
endif

1.15: 1.15-build 1.15-basic-test

1.16: 1.16-build
ifdef RUN_TESTS
	printf "this\nprogram prints\nthe longest line" | $(VALGRIND) ./bin/$@
endif

1.17: 1.17-build
ifdef RUN_TESTS
	printf "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n" | $(VALGRIND) ./bin/$@
	printf "Not longer than 80" | $(VALGRIND) ./bin/$@
endif

1.18: 1.18-build
ifdef RUN_TESTS
	printf "removes trailing whitespace          " | $(VALGRIND) ./bin/$@
endif

1.19: 1.19-build 1.19-basic-test

1.20: 1.20-build
ifdef RUN_TESTS
	printf "detabs\tlines\t" | $(VALGRIND) ./bin/$@
endif

1.21: 1.21-build
ifdef RUN_TESTS
	printf "tab  stops every        5 chars" | $(VALGRIND) ./bin/$@
endif

1.22: 1.22-build
ifdef RUN_TESTS
	printf "01234567890123456789" | $(VALGRIND) ./bin/$@
endif

1.23: 1.23-build
ifdef RUN_TESTS
	printf "// remove comments\nvoid main(){return 0;}" | $(VALGRIND) ./bin/$@
endif

1.24: 1.24-build
ifdef RUN_TESTS
	printf "// remove comments\nvoid main(){return 0;}" | $(VALGRIND) ./bin/$@
	printf "// remove comments\nvoid main(){return 0;}}" | $(VALGRIND) ./bin/$@
endif
