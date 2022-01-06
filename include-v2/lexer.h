#ifndef LEXER_H
#define LEXER_H


#include "fileinfo.h"
#include "token.h"
#include <stdbool.h>


typedef struct LEXER
{
	char currentChar;
	char * content;
	unsigned char column;
	unsigned int index;
	unsigned short line;
	FileInfo * fileInfo;
} Lexer;


Lexer * set_lexer(FileInfo * fileinfo, char * content);

void lexer_next(Lexer * lexer);
void lexer_skipWhitespace(Lexer * lexer);
void lexer_skipNewline(Lexer * lexer);

bool lexer_peek(Lexer * lexer, char gvalue);

Token * lexer_evaluateEqual(Lexer * lexer);

Token * lexer_getNextTokenEqual(Lexer * lexer);

Token * lexer_getNextToken(Lexer * lexer);

Token * lexer_nextWithToken(Lexer * lexer, Token * token);

Token * lexer_getString(Lexer * lexer);
Token * lexer_getChar(Lexer * lexer);
Token * lexer_getId(Lexer * lexer);
Token * lexer_getNumber(Lexer * lexer);


#endif
