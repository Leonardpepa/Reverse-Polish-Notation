#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "./fileHandler.h"


char* readFile(char* filePath){
    FILE* file = fopen(filePath, "r");

    if(file == NULL){
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);     
    int input_file_size = ftell(file);          
    rewind(file);

    char* sourceCode = (char*) malloc(input_file_size * sizeof(char));

    sourceCode[input_file_size] = '\0';

    char ch = fgetc(file);

    int counter = 0;

    while(ch != EOF){
        sourceCode[counter++] = ch;
        ch = fgetc(file);
    }

    fclose(file);
    return sourceCode;
}

int writeFile(char* textContent, char* fileOutputPath){
    (void) textContent;
    (void) fileOutputPath;

    assert(false && "Not implemented yet");
}
