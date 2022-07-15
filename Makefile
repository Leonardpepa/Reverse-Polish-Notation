.PHONY: default

default: compile

run: compile 
	./main test.rv

compile: fileHandler.o lexer.o main.o

main.o: main.c
	gcc main.c -o main lexer.o fileHandler.o

fileHandler.o: fileHandler.c fileHandler.h
	gcc -c fileHandler.c

lexer.o: lexer.c lexer.h 
	gcc -c lexer.c

clean: 
	rm -rf ./*.o
	rm -f fileHandler.o
	rm -f lexer.o
	rm -f main.o