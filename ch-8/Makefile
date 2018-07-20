# "build" is in the top-level makefile
8.5: clean
	make EX=$@ CH=ch-8 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@ ch-8
endif

# cat is 8.1
cat: clean
	echo "foo's conents" > foo.test
	echo "bar's contents" > bar.test
	echo "baz's contents" > baz.test
	$(COMPILE) -I ch-8/include/ ch-8/src/8.1.c -o bin/cat
	$(VALGRIND) ./bin/cat foo.test bar.test baz.test
	rm *.test

# fopen (and getc) is 8.2 through 8.4
# malloc is 8.6 through 8.8
fopen_j malloc_j:
	$(COMPILE) -I ch-8/$@/include/ ch-8/$@/src/*.c -o bin/$@
	$(VALGRIND) ./bin/$@
