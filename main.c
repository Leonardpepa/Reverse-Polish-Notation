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
    lexer->line = 1;
    lexer->position = 0;
    lexer->helperPosition = 0;
    lexer->textContent = code;
    
    fprintf(stdout, "Lexer output: \n");
    while(lexer->lookAhead.type != T_EOF){
        getNextToken(lexer);
        fprintf(stdout, "Token found: line %d: lexeme: %s, token kind: %s\n",lexer->line, lexer->lookAhead.lexeme, tokenAsString(lexer->lookAhead.type));
        
    }

    return 0;
}