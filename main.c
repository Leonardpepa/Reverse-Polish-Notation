#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include<string.h>
#include "./fileHandler.h"
#include "./lexer.h"


int main(int argc, char** argv){
    
    argc--;
    **argv++;

    if(argc == 0){
        fprintf(stderr, "Please provide a file to proccess\n");
        exit(1);
    }
    // variable to store source code for lexer
    char* code;
    // size of the file
    int size;

    readFile(*argv, &code, &size);
    
    Lexer* lexer;
    lexer->line = 0;
    lexer->position = 0;
    lexer->textContent = code;

    while(lexer->lookAhead.type != T_EOF){
        getNextToken(lexer);
        fprintf(stdout, "lexeme: %s, token: %d\n", lexer->lookAhead.lexeme, lexer->lookAhead.type);
    }

    return 0;
}