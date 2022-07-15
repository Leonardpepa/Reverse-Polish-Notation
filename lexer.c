#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <assert.h>
#include <stdbool.h>
#include"./lexer.h"

void getNextToken(Lexer* lexer){

    if(lexer->position == strlen(lexer->textContent)){
        Token token;
        token.lexeme = "end of line";
        token.type = T_EOF;

        lexer->lookAhead = token;
        
        return;
    }
    
    if(lexer->textContent[lexer->position]  == '+'){
        Token token;
        token.lexeme = "+";
        token.type = T_add;

        lexer->position++;
        lexer->lookAhead = token;

        return;
    }

    if(lexer->textContent[lexer->position]  == '-'){
        Token token;
        token.lexeme = "-";
        token.type = T_minus;

        lexer->position++;
        lexer->lookAhead = token;

        return;
    }

    if(lexer->textContent[lexer->position]  == '*'){
        Token token;
        token.lexeme = "*";
        token.type = T_mul;

        lexer->position++;
        lexer->lookAhead = token;

        return;
    }

    if(lexer->textContent[lexer->position]  == '/'){
        Token token;
        token.lexeme = "/";
        token.type = T_div;

        lexer->position++;
        lexer->lookAhead = token;

        return;
    }

}
void peekNextToken(Lexer* lexer){
    assert(false && "Not implemented yet");
}
