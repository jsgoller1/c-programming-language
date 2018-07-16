export EX=$(MAKECMDGOALS)

build: clean
	$(COMPILE) -D TEST_OUTPUT -I ch-1/include/ ch-1/src/$$EX.c -o bin/$$EX

1.3-4 1.5 1.7 1.11 1.15 1.19: build
	$(VALGRIND) ./bin/$@

1.6: build
	printf "d" | $(VALGRIND) ./bin/$@
	cat EOF | $(VALGRIND) ./bin/$@

1.8: build
	printf "this program prints whitespace	" | $(VALGRIND) ./bin/$@

1.9: build
	printf "this   program   strips   extra   spaces" | $(VALGRIND) ./bin/$@

1.10: build
	printf "this program escapes spaces and		tabs" |	$(VALGRIND) ./bin/$@

1.12: build
	printf "this program prints every word in input" | $(VALGRIND) ./bin/$@

1.13: build
	printf "this this this program program prints a a a a histogram" | $(VALGRIND) ./bin/$@

1.14: build
	printf "this program prints a char frequency histogram" | $(VALGRIND) ./bin/$@

1.16: build
	printf "this\nprogram prints\nthe longest line" | $(VALGRIND) ./bin/$@

1.17: build
	printf "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n" | $(VALGRIND) ./bin/$@
	printf "Not longer than 80" | $(VALGRIND) ./bin/$@

1.18: build
	printf "removes trailing whitespace          " | $(VALGRIND) ./bin/$@

1.20: build
	printf "detabs\tlines\t" | $(VALGRIND) ./bin/$@

1.21: build
	printf "tab  stops every        5 chars" | $(VALGRIND) ./bin/$@

1.22: build
	printf "01234567890123456789" | $(VALGRIND) ./bin/$@

1.23: build
	printf "// remove comments\nvoid main(){return 0;}" | $(VALGRIND) ./bin/$@

1.24: build
	printf "// remove comments\nvoid main(){return 0;}" | $(VALGRIND) ./bin/$@
	printf "// remove comments\nvoid main(){return 0;}}" | $(VALGRIND) ./bin/$@
