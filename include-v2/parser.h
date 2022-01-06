#ifndef PARSER_H
#define PARSER_H


#include "lexer.h"


typedef struct PARSER
{
    Lexer * lexer;
    Token * currentToken;
    Token * previousToken;
} Parser;


Parser * set_parser(Lexer * lexer);


#endif
