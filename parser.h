#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include "./lexer.h"

Lexer* lexer;

void parse_code(Lexer* lex);

void s();

void stmts();

void listStmts();

void stmt();

void rev();

void rec_rev();

void match(TokenKind token);

void syntax_error(TokenKind token);

void simple_syntax_error();




#endif