#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include<string.h>
#include "./fileHandler.h"
#include "./lexer.h"
#include "./parser.h"


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
    
    // get lookahead token
    getNextToken(lexer);
    // print lexer

    // print the first look ahead token
    fprintf(stdout, "Tokens Found by lexical analysis \n");
    printToken(lexer);
    parse_code(lexer);

    return 0;
}