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
