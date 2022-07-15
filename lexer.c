#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <assert.h>
#include <stdbool.h>
#include<ctype.h>
#include"./lexer.h"

char* tokenAsString(TokenKind kind){
    switch (kind)
    {
    case T_error:
        return "Error";
    case T_num:
        return "Number";
    case T_add:
        return "Addition";
    case T_minus:
        return "Subtraction";
    case T_mul:
        return "Multiplication";
    case T_div:
        return "Division";
    case T_EOF:
        return "EOF";
    case T_semi:
        return "Semicolon";
    default:
        return "Error";
    }
}

void getNextToken(Lexer* lexer){
    
    // parse integers 
    if(isdigit(lexer->textContent[lexer->position])){
        
        int i = lexer->position;
        while (isdigit(lexer->textContent[lexer->position])){   
            lexer->position++;
            lexer->helperPosition++;
        }

        char* number = (char*) malloc((lexer->position - i) * sizeof(char));

        for(int k=0; k<lexer->position - i; k++){
            number[k] = lexer->textContent[i+k];
        }
        number[lexer->position -  i] = '\0';
        lexer->lookAhead = (Token){number, T_num};
        return;
    }

    if(lexer->textContent[lexer->position]  == '\n'){
        lexer->position++;
        lexer->helperPosition = 0;
        lexer->line++;
        lexer->lookAhead = (Token){"", T_error};
        return;
    }

    if(lexer->textContent[lexer->position]  == ' ' || lexer->textContent[lexer->position]  == '\t' || lexer->textContent[lexer->position]  == 13){
        lexer->position++;
        lexer->helperPosition++;
        lexer->lookAhead = (Token){"", T_error};
        return;
    }

    if(lexer->position == strlen(lexer->textContent)){
        lexer->lookAhead = (Token){"EOF", T_EOF};
        return;
    }
    
    if(lexer->textContent[lexer->position]  == '+'){

        lexer->lookAhead = (Token){"+", T_add};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    if(lexer->textContent[lexer->position]  == '-'){

        lexer->lookAhead = (Token){"-", T_minus};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    if(lexer->textContent[lexer->position]  == '*'){

        lexer->lookAhead = (Token){"*", T_mul};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    if(lexer->textContent[lexer->position]  == '/'){

        lexer->lookAhead = (Token){"/", T_div};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    if(lexer->textContent[lexer->position]  == ';'){

        lexer->lookAhead = (Token){";", T_semi};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    

    lexer->lookAhead = (Token){"error", T_error};
    fprintf(stderr, "Unexpected token: %c on line %d, position %d\n", lexer->textContent[lexer->position], lexer->line, lexer->helperPosition);
    lexer->position++;
    lexer->helperPosition++;
    return;
}
void peekNextToken(Lexer* lexer){
    assert(false && "Not implemented yet");
}
