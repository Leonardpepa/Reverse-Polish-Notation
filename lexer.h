#ifndef LEXER_H
#define LEXER_H

#include<stdlib.h>

typedef enum {T_error,T_EOF, T_num, T_op, T_semi, T_start, T_end} TokenKind;

typedef struct{
    char* lexeme;
    TokenKind type;
}Token;

typedef struct{
    char* textContent;
    Token lookAhead;
    int position;
    int helperPosition;
    int line;
}Lexer;


char* tokenAsString(TokenKind kind);
void getNextToken(Lexer* lexer);
void peekNextToken(Lexer* lexer);


#endif