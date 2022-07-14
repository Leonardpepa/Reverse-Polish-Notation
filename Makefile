fileHandler: fileHandler.c
	gcc fileHandler.c -o fileHandler

run: fileHandler
	./fileHandler test.rv