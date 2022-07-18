.PHONY: default

default: compile


compile: fileHandler.o lexer.o parser.o jvm_intermed.o main.o

main.o: main.c
	gcc main.c -o main lexer.o parser.o jvm_intermed.o fileHandler.o

fileHandler.o: fileHandler.c fileHandler.h
	gcc -c fileHandler.c

lexer.o: lexer.c lexer.h 
	gcc -c lexer.c

parser.o: parser.c parser.h
	gcc -c parser.c

jvm_intermed.o: jvm_intermed.c jvm_intermed.h
	gcc -c jvm_intermed.c

clean:
	rm -f ./*.txt
	rm -f ./*.o
	rm -f fileHandler.o
	rm -f lexer.o
	rm -f jvm_intermed.o
	rm -f parser.o
	rm -f main.o
	rm -f main
	rm -f *.j
	rm -f *.class