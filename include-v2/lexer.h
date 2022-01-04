#ifndef LEXER_H
#define LEXER_H


typedef struct LEXER
{
	char currentChar;
	char * content;
	unsigned char column;
	unsigned int index;
	unsigned short line;
	FileInfo * fileInfo;
} Lexer;


Lexer * set_lexer(char * content);


#endif
