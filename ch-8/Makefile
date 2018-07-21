# cat is 8.1
cat: clean
	echo "foo's conents" > ./bin/foo.test
	echo "bar's contents" > ./bin/bar.test
	echo "baz's contents" > ./bin/baz.test
	$(COMPILE) -I ch-8/include/ ch-8/src/8.1.c -o bin/cat
	$(VALGRIND) ./bin/cat ./bin/foo.test ./bin/bar.test ./bin/baz.test
	rm ./bin/*.test

8.5: 8.5-build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@ ch-8
endif

# fopen (and getc) is 8.2 through 8.4
# malloc is 8.6 through 8.8
fopen_j malloc_j:
	$(COMPILE) -I ch-8/$@/include/ ch-8/$@/src/*.c -o bin/$@
	$(VALGRIND) ./bin/$@
