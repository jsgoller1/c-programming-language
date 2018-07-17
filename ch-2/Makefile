include vars.mk

build:
	$(COMPILE) -I ch-2/include ch-2/src/$$EX.c -o bin/$$EX

2.1 2.2 2.3 2.4: clean
	make EX=$@ build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@
endif

#2.x: clean
#	make EX=$@ build
#ifdef RUN_TESTS
#	printf "d" | $(VALGRIND) ./bin/$@
#	cat EOF | $(VALGRIND) ./bin/$@
#endif
