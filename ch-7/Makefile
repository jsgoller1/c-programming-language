include vars.mk

# "build" is in the top-level makefile
7.2 7.3 7.4 7.5 7.6 7.7 7.8 7.9: clean
	make EX=$@ CH=ch-7 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@
endif

7.1:  clean
	make EX=$@ CH=ch-7 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@ -u "this is a test string"
	$(VALGRIND) ./bin/$@ -l "THIS IS A TEST STRING"
endif
