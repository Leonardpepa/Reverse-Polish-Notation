#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"./fileHandler.h"
#include"./jvm_intermed.h"

void addPrint(char* filepath){
    addInstruction("getstatic java/lang/System/out Ljava/io/PrintStream;", filepath);
    addInstruction("swap", filepath);
    addInstruction("invokevirtual java/io/PrintStream/print(I)V", filepath);

    addInstruction("getstatic java/lang/System/out Ljava/io/PrintStream;", filepath);
    addInstruction("ldc \"\n\"", filepath);
    addInstruction("invokevirtual java/io/PrintStream/print(Ljava.lang.String;)V", filepath);
}

void addInteger(char* lexeme, char* filepath){
    int x = atoi(lexeme);
    char instruction[200];
	if (x == -1) sprintf(instruction,"iconst_m1");
	else if (x >=0 && x <=5) sprintf(instruction,"iconst_%d",x);
	else if (x > -128 && x < 127) sprintf(instruction,"bipush %d",x);
	else sprintf(instruction,"sipush %d",x);
	addInstruction(instruction, filepath);
}

void createBaseClass(char* filepath){
    writeFile(".class public test",filepath);
    addInstruction(".super java/lang/Object", filepath);
    appendToFile("\n", filepath);
    addInstruction(".method public static main([Ljava/lang/String;)V" , filepath);
    addInstruction(" .limit locals 10" , filepath);
    addInstruction(" .limit stack 10" , filepath);
    appendToFile("\n", filepath);
}


void addEndMethod(char* filepath){
    addInstruction("return", filepath);
    addInstruction(".end method", filepath);
    appendToFile("\n", filepath);
}


void addInstruction(char* instruction, char* filepath){
    char* newChar = malloc((strlen(instruction) + 1) * sizeof(char));
    newChar[0] = '\n';
    newChar[strlen(instruction) + 1] = '\0';

    for(int i=0; i<strlen(instruction); i++){
        newChar[i+1] = instruction[i];
    }
    appendToFile(newChar, filepath);
}