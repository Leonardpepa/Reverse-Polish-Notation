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
        fprintf(stderr, "Please provide a file\n");
        exit(1);
    }
    // variable to store source code for lexer
    char* code;
    // size of the file
    int size;

    readFile(argv[0], &code, &size);

    
    char* jasminFile = (char*) malloc((strlen(argv[0]) + 2) *  sizeof(char));
    
    strcpy(jasminFile, argv[0]);
    jasminFile[strlen(argv[0])] = '.';
    jasminFile[strlen(argv[0]) + 1] = 'j';
    jasminFile[strlen(argv[0]) + 2] = '\0';


    Lexer* lexer;
    lexer->line = 1;
    lexer->position = 0;
    lexer->helperPosition = 0;
    lexer->textContent = code;
    
    // get lookahead token
    getNextToken(lexer);

    // print lexer
    fprintf(stdout, "Tokens Found by lexical analysis \n");
    
    // print the first look ahead token
    printToken(lexer);

    parse_code(lexer,  jasminFile);

    return 0;
}