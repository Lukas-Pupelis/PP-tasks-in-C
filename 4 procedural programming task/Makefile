.PHONY: testing, compileTest

compile: main.c function.c
	gcc -o inserter main.c function.c
	
run:
	inserter

compileTest: test.c function.c
	gcc -o test test.c function.c

testing:
	test