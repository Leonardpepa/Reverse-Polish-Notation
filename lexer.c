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
    case T_op:
        return "op";
    case T_EOF:
        return "EOF";
    case T_semi:
        return "Semicolon";
    case T_start:
        return "Start";
    case T_end:
        return "End";
    default:
        return "Error";
    }
}

char* opAsString(char op){
    switch (op)
    {
    case '+':
        return "iadd";
    case '-':
        return "isub";
    case '*':
        return "imul";
    case '/':
        return "idiv";
    default:
        exit(1);
    }
}

void printToken(Lexer* lexer){
    fprintf(stdout, "Line %d: Token found, lexeme: %s, kind: %s\n", lexer->line, lexer->lookAhead.lexeme, tokenAsString(lexer->lookAhead.type));
}


void getNextToken(Lexer* lexer){

    // parse keywords
    if(isalpha(lexer->textContent[lexer->position])){
        int i = lexer->position;
        
        while (isalpha(lexer->textContent[lexer->position])){   
            lexer->position++;
            lexer->helperPosition++;
        }

        char* keyword = (char*) malloc((lexer->position - i) * sizeof(char));

        for (int k=0; k<lexer->position - i; k++){
            keyword[k] = lexer->textContent[i+k];
        }
        keyword[lexer->position -  i] = '\0';

        if(strcmp(keyword, "start") == 0){
            lexer->lookAhead = (Token){keyword, T_start};
            return;
        }else if (strcmp(keyword, "end") == 0){
            lexer->lookAhead = (Token){keyword, T_end};
            return;
        }else{
            lexer->lookAhead = (Token){"error", T_error};
            fprintf(stdout, "Unexpected token: \"%s\", on line %d on position %ld\n", keyword, lexer->line, lexer->helperPosition - strlen(keyword));
            free(keyword);
            return;
        }
    }

    // parse integers 
    if(isdigit(lexer->textContent[lexer->position])){

        int i = lexer->position;
        while (isdigit(lexer->textContent[lexer->position])){   
            lexer->position++;
            lexer->helperPosition++;
        }

        char* number = (char*) malloc((lexer->position - i) * sizeof(char));

        for (int k=0; k<lexer->position - i; k++){
            number[k] = lexer->textContent[i+k];
        }
        number[lexer->position -  i] = '\0';
        lexer->lookAhead = (Token){number, T_num};
        return;
    }

    if (lexer->textContent[lexer->position]  == '\n'){
        lexer->position++;
        lexer->helperPosition = 0;
        lexer->line++;
        // lexer->lookAhead = (Token){"", T_error};
        getNextToken(lexer);
        return;
    }

    if (lexer->textContent[lexer->position]  == ' ' || lexer->textContent[lexer->position]  == '\t' || lexer->textContent[lexer->position]  == '\r' ){
        lexer->position++;
        lexer->helperPosition++;
        // lexer->lookAhead = (Token){"", T_error};
        getNextToken(lexer);
        return;
    }

    if (lexer->position == strlen(lexer->textContent)){
        lexer->lookAhead = (Token){"EOF", T_EOF};
        return;
    }
    
    if (lexer->textContent[lexer->position]  == '+'){

        lexer->lookAhead = (Token){"+", T_op};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    if (lexer->textContent[lexer->position]  == '-'){

        lexer->lookAhead = (Token){"-", T_op};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    if (lexer->textContent[lexer->position]  == '*'){

        lexer->lookAhead = (Token){"*", T_op};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    if (lexer->textContent[lexer->position]  == '/'){

        lexer->lookAhead = (Token){"/", T_op};
        lexer->position++;
        lexer->helperPosition++;

        return;
    }

    if (lexer->textContent[lexer->position]  == ';'){

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
