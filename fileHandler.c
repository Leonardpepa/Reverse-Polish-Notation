#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "./fileHandler.h"

void readFile(char* filePath, char** str, int* size){
    FILE* file = fopen(filePath, "r");

    if(file == NULL){
        fprintf(stderr, "Error while opening file: %s\n", filePath);
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
    FILE* file = fopen(fileOutputPath, "w");

    if(file == NULL){
        fprintf(stderr, "Error while proccessing file: %s\n", fileOutputPath);
        return 0;
    }

    for(int i=0; i<strlen(textContent); i++){
        fprintf(file, "%c", textContent[i]);
    }

    fclose(file);
    return 1;
}


int appendToFile(char* textContent, char* fileOutputPath){
    FILE* file = fopen(fileOutputPath, "a");

    if(file == NULL){
        fprintf(stderr, "Error while proccessing file: %s\n", fileOutputPath);
        return 0;
    }

    for(int i=0; i<strlen(textContent); i++){
        fprintf(file, "%c", textContent[i]);
    }

    fclose(file);
    return 1;
}

