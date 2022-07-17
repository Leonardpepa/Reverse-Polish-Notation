#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"./parser.h"

void parse_code(Lexer* lex){
    lexer = lex;
    s();
    if(lexer->lookAhead.type == T_EOF){
        fprintf(stdout, "Parsing completed with no errors\n");
    }else{
        syntax_error(T_EOF);
    }
}

void s(){
    if (lexer->lookAhead.type == T_start){
        match(T_start);
        stmts();
        match(T_end);
    }else{
        syntax_error(T_start);
    }
    
}


void stmts(){
    if(lexer->lookAhead.type == T_num){
        stmt();
        match(T_semi);
        listStmts();
    }else{
        syntax_error(T_num);
    }
}

void listStmts(){
    if(lexer->lookAhead.type == T_num){
        stmts();
    }else if(lexer->lookAhead.type == T_semi){
        syntax_error(T_semi);
    }
}

void stmt(){
    if(lexer->lookAhead.type == T_num){
        rev();
    }else{
        syntax_error(T_num);
    }
}


void rev(){
    if(lexer->lookAhead.type == T_num){
        match(T_num);
        rec_rev();
    }else{
        syntax_error(T_num);
    }
}

void rec_rev(){
    if(lexer->lookAhead.type == T_num){
        rev();
        match(T_op);
        rec_rev();
    }else if(lexer->lookAhead.type != T_op && lexer->lookAhead.type != T_semi){
        simple_syntax_error();
    }
}

void match(TokenKind token){
    if(lexer->lookAhead.type == token){
        getNextToken(lexer);
        printToken(lexer);
    }else{
        syntax_error(token);
    }
}

void syntax_error(TokenKind token){
    fprintf(stderr, "Syntax Error reading %s at line %d position %d\n", tokenAsString(lexer->lookAhead.type), lexer->line, lexer->helperPosition);
    fprintf(stderr, "Expected %s but found %s\n", tokenAsString(token), tokenAsString(lexer->lookAhead.type));
    exit(1);
}

void simple_syntax_error(){
    fprintf(stderr, "Syntax Error reading %s at line %d position %d\n", tokenAsString(lexer->lookAhead.type), lexer->line, lexer->helperPosition);
    exit(1);
}
