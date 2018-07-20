include vars.mk

# kwcount is 6.1
kwcount: clean
	$(COMPILE) -I ch-6/$@/include/ ch-6/$@/src/*.c -o bin/$@
	#cat ch-6/$@/$@-test.c | $(VALGRIND) ./bin/$@
	cat ch-6/$@/src/$@.c | $(VALGRIND) ./bin/$@

# charmatch is 6.2
 charmatch: clean
	$(COMPILE) -I ch-6/$@/include/ ch-6/$@/src/*.c -o bin/$@
	cat ch-6/$@/$@-test.* | $(VALGRIND) ./bin/$@ 1

# crossref is 6.3
# wordcount is 6.4
# hashtable is 6.5 and 6.6
 crossref wordcount hashtable: clean
	$(COMPILE) -I ch-6/$@/include/ ch-6/$@/src/*.c -o bin/$@
	cat ch-6/$@/$@-test.* | $(VALGRIND) ./bin/$@
