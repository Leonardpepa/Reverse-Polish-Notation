.PHONY: default

default: compile

run: compile 
	./main test.rv

compile: fileHandler.o lexer.o parser.o main.o

main.o: main.c
	gcc main.c -o main lexer.o parser.o fileHandler.o

fileHandler.o: fileHandler.c fileHandler.h
	gcc -c fileHandler.c

lexer.o: lexer.c lexer.h 
	gcc -c lexer.c

parser.o: parser.c parser.h
	gcc -c parser.c

clean:
	rm -f ./*.txt
	rm -f ./*.o
	rm -f fileHandler.o
	rm -f lexer.o
	rm -f parser.o
	rm -f main.o
	rm -f main