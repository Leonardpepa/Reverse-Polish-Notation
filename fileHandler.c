#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "./fileHandler.h"

void readFile(char* filePath, char** str, int* size){
    FILE* file = fopen(filePath, "r");

    if(file == NULL){
        str = NULL;
        *size = -1;
    }
    
    fseek(file, 0, SEEK_END);     
    int input_file_size = ftell(file);          
    rewind(file);
    char *tempStr = (char*) malloc((input_file_size)* sizeof(char));
    *size = input_file_size;

    tempStr[input_file_size] = '\0';

    char ch = fgetc(file);

    int counter = 0;

    while(ch != EOF){
        tempStr[counter++] = ch;
        ch = fgetc(file);
    }

    *str = tempStr;
    
    fclose(file);
}

int writeFile(char* textContent, char* fileOutputPath){
    (void) textContent;
    (void) fileOutputPath;

    assert(false && "Not implemented yet");
}
