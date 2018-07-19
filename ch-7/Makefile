include vars.mk

# "build" is in the top-level makefile
7.3 7.6 7.7 7.8 7.9: clean
	make EX=$@ CH=ch-7 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@
endif

7.1: clean
	make EX=$@ CH=ch-7 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@ -u "this is a test string"
	$(VALGRIND) ./bin/$@ -l "THIS IS A TEST STRING"
endif

7.2: clean
	make EX=$@ CH=ch-7 build
ifdef RUN_TESTS
	printf "0xff\n" | $(VALGRIND) ./bin/$@
	printf "\037" | $(VALGRIND) ./bin/$@
endif

7.4: clean
	make EX=$@ CH=ch-7 build
ifdef RUN_TESTS
	printf "5 - 4.0 - foobar\n" | $(VALGRIND) ./bin/$@
	printf "300 + 5" | $(VALGRIND) ./bin/$@
endif

7.5: clean
	make EX=$@ CH=ch-7 build
ifdef RUN_TESTS
	echo "300 5 +" | $(VALGRIND) ./bin/$@
	echo "300 5 + 200 5 - +" | $(VALGRIND) ./bin/$@
	echo "1 5 *" | $(VALGRIND) ./bin/$@
	echo "10 5 /" | $(VALGRIND) ./bin/$@
	-echo "10 0 /" | $(VALGRIND) ./bin/$@
endif
