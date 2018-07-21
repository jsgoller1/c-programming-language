7.1: 7.1-build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@ -u "this is a test string"
	$(VALGRIND) ./bin/$@ -l "THIS IS A TEST STRING"
endif

7.2: 7.2-build
ifdef RUN_TESTS
	printf "0xff\n" | $(VALGRIND) ./bin/$@
	printf "\037" | $(VALGRIND) ./bin/$@
endif

7.3: 7.3-build 7.3-basic-test

7.4: 7.4-build
ifdef RUN_TESTS
	printf "5 - 4.0 - foobar\n" | $(VALGRIND) ./bin/$@
	printf "300 + 5" | $(VALGRIND) ./bin/$@
endif

7.5: 7.5-build
ifdef RUN_TESTS
	echo "300 5 +" | $(VALGRIND) ./bin/$@
	echo "300 5 + 200 5 - +" | $(VALGRIND) ./bin/$@
	echo "1 5 *" | $(VALGRIND) ./bin/$@
	echo "10 5 /" | $(VALGRIND) ./bin/$@
	-echo "10 0 /" | $(VALGRIND) ./bin/$@
endif

7.6: 7.6-build
ifdef RUN_TESTS
	printf "a\nb\nc\nd\ne" > ./bin/7.6-test-1.txt
	printf "a\nb\nc\nd\ne" > ./bin/7.6-test-2.txt
	$(VALGRIND) ./bin/$@ ./bin/7.6-test-2.txt ./bin/7.6-test-1.txt
	echo "foobar" >> ./bin/7.6-test-1.txt
	echo "foobaz" >> ./bin/7.6-test-2.txt
	$(VALGRIND) ./bin/$@ ./bin/7.6-test-2.txt ./bin/7.6-test-1.txt
endif

7.7: 7.7-build
ifdef RUN_TESTS
	printf "match-on-this" > ./bin/7.7-pattern.txt
	printf "match-on-this" | $(VALGRIND) ./bin/$@ -f ./bin/7.7-pattern.txt
	printf "match because x" | $(VALGRIND) ./bin/$@ -x -f ./bin/7.7-pattern.txt
	printf "no match" | $(VALGRIND) ./bin/$@ -f ./bin/7.7-pattern.txt
endif

7.8: 7.8-build
ifdef RUN_TESTS
	for LINE_NO in `seq 1 120`; do \
		echo "$$LINE_NO: ABCDEFGHIJKLMNOPQRSTUVWXYZ" >> ./bin/7.8-test.txt; \
	done
	$(VALGRIND) ./bin/$@ ./bin/7.8-test.txt
endif

7.9: 7.9-build 7.9-basic-test
