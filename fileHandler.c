#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./fileHandler.h"

char* readFile(char* filePath){
    FILE* file = fopen(filePath, "r");

    if(file == NULL){
        fprintf(stderr, "Cannot open file: %s \n", filePath);
        exit(1);
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

}



int main(int argc, char** argv){

    // skip programm
    argc--;
    **argv++;
    char* sourceCode;
    if(argc <= 0){
        fprintf(stderr, "Please provide a file\n");
        exit(1);
    }

    if(argc > 0){
        sourceCode = readFile(*argv);
        printf("%s\n", sourceCode);
    }


    return 0;
}