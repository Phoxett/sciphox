#ifndef LEXER_H
#define LEXER_H


#include "token.h"


typedef struct LEXER
{
	char currentChar;
	unsigned char column;
	unsigned int line;
	unsigned int index;
	char * content;
} Lexer;


Lexer * init_lexer(char * content);
void lexer_advance(Lexer * lexer);
void lexer_skipWhitespace(Lexer * lexer);
void lexer_skipNewline(Lexer * lexer);
Token * lexer_getNextToken(Lexer * lexer);
Token * lexer_getString(Lexer * lexer);
Token * lexer_getId(Lexer * lexer);
Token * lexer_getNumber(Lexer * lexer);
Token * lexer_advanceWithToken(Lexer * lexer, Token * token);
char * lexer_getCurrentCharAsString(Lexer * lexer);


#endif
