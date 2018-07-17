include vars.mk

3.1 3.2 3.3 3.4 3.5 3.6: clean
	make EX=$@ CH=ch-3 build
ifdef RUN_TESTS
	$(VALGRIND) ./bin/$@
endif
