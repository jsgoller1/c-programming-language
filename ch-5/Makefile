5.1: 5.1-build
ifdef RUN_TESTS
	echo "-55" | $(VALGRIND) ./bin/$@
	-echo "-" | $(VALGRIND) ./bin/$@ # This causes a false positive in Valgrind; see README
endif

5.2: 5.2-build
ifdef RUN_TESTS
	printf "4.5" | $(VALGRIND) ./bin/$@
	echo "-12.5" | $(VALGRIND) ./bin/$@
	printf ".5" | $(VALGRIND) ./bin/$@
	printf "0.5" | $(VALGRIND) ./bin/$@
	printf "2." | $(VALGRIND) ./bin/$@
	-echo "-" | $(VALGRIND) ./bin/$@ # This causes a false positive in Valgrind; see README
endif

5.3: 5.3-build 5.3-basic-test
5.4: 5.4-build 5.4-basic-test
5.5: 5.5-build 5.5-basic-test
5.6: 5.6-build 5.6-basic-test

5.7: 5.7-build
ifdef RUN_TESTS
	printf "A line\nQ line\nD line\nC line\nS line\n" | $(VALGRIND) ./bin/$@
	printf "" | $(VALGRIND) ./bin/$@
endif

5.8-9: 5.8-9-build 5.8-9-basic-test
5.10: 5.10-build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@ 10 5 +
	$(VALGRIND) ./bin/$@ 10 5 /
	$(VALGRIND) ./bin/$@ 5 10 -
	$(VALGRIND) ./bin/$@ 5 10 "*"
	@# ((10 5 +) + (10 / 5)) + ((5 10 -) + (5 10 *))
	$(VALGRIND) ./bin/$@ 10 5 + 10 5 / + 5 10 - 5 10 "*" + +
	@# tests that should cause exceptions
	-$(VALGRIND) ./bin/$@ 10 5 %
	-$(VALGRIND) ./bin/$@ herp derp ferp
	-$(VALGRIND) ./bin/$@
endif

# tabber covers the entab / detab exercises in 5.11 and 5.12
# tail is exercise 5.13
tabber tail: clean
	$(COMPILE) -I ch-5/$@/include ch-5/$@/src/*.c -o bin/$@
ifdef RUN_TESTS
	./ch-5/$@/$@-test.sh
endif

# sort is exercises 5.14 through 5.17
sort: clean
	$(COMPILE) -I ch-5/sort/include/ ch-5/sort/src/*.c -o bin/$@
ifdef RUN_TESTS
	cat ch-5/sort/sort-test.txt | $(VALGRIND) ./bin/$@
	cat ch-5/sort/sort-test-mixed-case.txt | $(VALGRIND) ./bin/$@ -f
	cat ch-5/sort/sort-test-homedir.txt | $(VALGRIND) ./bin/$@ -d -r
	cat ch-5/sort/sort-test-subfields.txt | $(VALGRIND) ./bin/$@ -r -i -n
endif

# decl/undecl are exercises 5.18 through 5.20
decl undecl: clean
	$(COMPILE) -I ch-5/decl/include/ ch-5/decl/src/common/*.c ch-5/decl/src/$@-main.c -o bin/$@
	./ch-5/decl/$@-test.sh
