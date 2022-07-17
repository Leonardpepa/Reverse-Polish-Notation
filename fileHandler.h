#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include<stdlib.h>

void readFile(char* filePath, char** str, int* size);
int writeFile(char* textContent, char* fileOutputPath);
int appendToFile(char* textContent, char* fileOutputPath);


#endif


