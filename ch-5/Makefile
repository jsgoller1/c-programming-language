5.1: 5.1-build
ifdef RUN_TESTS
	echo "-55" | $(VALGRIND) ./bin/$@
	-echo "-" | $(VALGRIND) ./bin/$@ # This causes a false positive in Valgrind; see README
endif


5.2: 5.2-build 5.2-basic-test
5.3: 5.3-build 5.3-basic-test
5.4: 5.4-build 5.4-basic-test
5.5: 5.5-build 5.5-basic-test
5.6: 5.6-build 5.6-basic-test
5.7: 5.7-build 5.7-basic-test
5.8-9: 5.8-9-build 5.8-9-basic-test
5.10: 5.10-build 5.10-basic-test

# tabber covers the entab / detab exercises in 5.11 and 5.12
tabber: clean
	$(COMPILE) -I ch-5/$@/include ch-5/$@/src/*.c -o bin/$@
	./ch-5/$@/$@-test.sh

# tail is exercise 5.13; I decided external tests were better than unit tests.
tail: clean
	$(COMPILE) -I ch-5/tail/include/ ch-5/tail/src/5.13.c -o bin/tail
	./tail/tail_test.sh

# sort is exercises 5.14 through 5.17
sort: clean
	$(COMPILE) -I ch-5/sort/include/ ch-5/sort/src/{compare,input,main,sort,strings}.c -o bin/$@
	cat ch-5/sort/sort-test-subfields.txt | $(VALGRIND) ./bin/$@ -r -i -n

# decl/undecl are exercises 5.18 through 5.20
decl undecl: clean
	$(COMPILE) -I ch-5/decl/include/ ch-5/decl/src/{decl,dirdecl,gettoken,$@-main,vars}.c -o bin/$@
	./ch-5/decl/$@-test.sh
