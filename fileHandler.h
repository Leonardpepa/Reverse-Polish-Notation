#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <stdlib.h>

char* filePath;
char* outputPath;
char* readFile(char* filePath);
int writeFile(char* textContent, char* fileOutputPath);

#endif


