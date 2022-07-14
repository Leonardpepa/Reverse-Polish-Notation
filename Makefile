.PHONY: default

default: compile

compile: fileHandler.o 

fileHandler.o: fileHandler.c fileHandler.h
	gcc -c fileHandler.c

clean: 
	rm -rf ./*.o
	rm -f fileHandler.o