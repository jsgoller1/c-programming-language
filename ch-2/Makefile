include vars.mk

2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.10: clean
	make EX=$@ CH=ch-2 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@
endif
