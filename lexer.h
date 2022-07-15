#ifndef LEXER_H
#define LEXER_H

#include<stdlib.h>

typedef enum {T_error,T_EOF, T_num, T_add, T_minus, T_mul, T_div} TokenKind;
typedef struct{
    char* lexeme;
    TokenKind type;
}Token;

typedef struct{
    char* textContent;
    Token lookAhead;
    int position;
    int line;
}Lexer;



void getNextToken(Lexer* lexer);
void peekNextToken(Lexer* lexer);


#endif