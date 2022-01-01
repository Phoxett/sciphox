#include "../include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


Lexer * init_lexer(char * contents)
{
	Lexer * lexer = calloc(1, sizeof(struct LEXER));
	lexer->content = contents;
	lexer->index = 0;
	lexer->column = 1;
	lexer->line = 1;
	lexer->currentChar = contents[lexer->index];

	return lexer;
}

void lexer_advance(Lexer * lexer)
{
	if (lexer->currentChar != '\0' && lexer->index < strlen(lexer->content))
	{
		lexer->index += 1;
		lexer->column += 1;
		lexer->currentChar = lexer->content[lexer->index];
	}
}

void lexer_skipWhitespace(Lexer * lexer)
{
	while (lexer->currentChar == ' ')
	{
		lexer_advance(lexer);
	}
}


void lexer_skipNewline(Lexer * lexer)
{
	while (lexer->currentChar == '\n')
	{
		lexer_advance(lexer);
		lexer->column += 1;
		lexer->line += 1;
	}
}

Token * lexer_getNextToken(Lexer * lexer)
{
	while (lexer->currentChar != '\0' && lexer->index < strlen(lexer->content))
	{
		if (lexer->currentChar == ' ')
			lexer_skipWhitespace(lexer);
		if (lexer->currentChar == '\n')
			lexer_skipNewline(lexer);
		if (isalpha(lexer->currentChar))
			return lexer_getId(lexer);
		if (isdigit(lexer->currentChar))
			return lexer_getNumber(lexer);

		if (lexer->currentChar == '"')
			return lexer_getString(lexer);

		switch (lexer->currentChar)
		{
			case '=': return lexer_advanceWithToken(lexer, init_token(TOKEN_EQUALS, lexer_getCurrentCharAsString(lexer))); break;
			case ';': return lexer_advanceWithToken(lexer, init_token(TOKEN_SEMI, lexer_getCurrentCharAsString(lexer))); break;
			case '(': return lexer_advanceWithToken(lexer, init_token(TOKEN_LPAREN, lexer_getCurrentCharAsString(lexer))); break;
			case ')': return lexer_advanceWithToken(lexer, init_token(TOKEN_RPAREN, lexer_getCurrentCharAsString(lexer))); break;
			case '{': return lexer_advanceWithToken(lexer, init_token(TOKEN_LBRACE, lexer_getCurrentCharAsString(lexer))); break;
			case '}': return lexer_advanceWithToken(lexer, init_token(TOKEN_RBRACE, lexer_getCurrentCharAsString(lexer))); break;
			case ',': return lexer_advanceWithToken(lexer, init_token(TOKEN_COMMA, lexer_getCurrentCharAsString(lexer))); break;
		}
	}

	return init_token(TOKEN_EOF, "\0");
}

Token * lexer_getString(Lexer * lexer)
{
	lexer_advance(lexer);

	char * value = calloc(1, sizeof(char));
	value[0] = '\0';

	while (lexer->currentChar != '"')
	{
		char * s = lexer_getCurrentCharAsString(lexer);
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);

		lexer_advance(lexer);
	}

	lexer_advance(lexer);

	return init_token(TOKEN_STRING, value);
}

Token * lexer_getId(Lexer * lexer)
{
	char * value = calloc(1, sizeof(char));
	value[0] = '\0';

	while (isalnum(lexer->currentChar))
	{
		char * s = lexer_getCurrentCharAsString(lexer);
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_advance(lexer);
	}
	
	return init_token(TOKEN_ID, value);
}


Token * lexer_getNumber(Lexer * lexer)
{
	char * value = calloc(1, sizeof(char));
	value[0] = '\0';
	char dot = 0;
	while (isdigit(lexer->currentChar))
	{
		char * s = lexer_getCurrentCharAsString(lexer);
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_advance(lexer);
		if ((lexer->currentChar == '.') && dot < 1)
		{
			dot = 1;
			char * s = lexer_getCurrentCharAsString(lexer);
			value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
			strcat(value, s);
			lexer_advance(lexer);
			while (isdigit(lexer->currentChar))
			{
				char * s = lexer_getCurrentCharAsString(lexer);
				value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
				strcat(value, s);
				lexer_advance(lexer);
			}
			
			return init_token(TOKEN_FLOAT, value);
		}
	}
	
	return init_token(TOKEN_INT, value);
}


Token * lexer_advanceWithToken(Lexer * lexer, Token * token)
{
	lexer_advance(lexer);

	return token;
}

char * lexer_getCurrentCharAsString(Lexer * lexer)
{
	char * str = calloc(2, sizeof(char));
	str[0] = lexer->currentChar;
	str[1] = '\0';

	return str;
}
