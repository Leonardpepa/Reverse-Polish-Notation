#ifndef JVM_INTERMED_H
#define JVM_INTERMED_H

#include<stdlib.h>

void createBaseClass(char* filepath);
void addInstruction(char* instruction, char* filepath);
void addEndMethod(char* filepath);
void addInteger(char* lexeme, char* filepath);
void addPrint(char* filepath);

#endif