#include "../include-v2/lexer.h"
#include "../include-v2/util.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


Token * lexer_getString(Lexer * lexer)
{
    lexer_next(lexer);
	char * value = calloc(1, sizeof(char));
	value[0] = '\0';

	while (lexer->currentChar != '"')
	{
		char * s = charToString(lexer->currentChar);
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);

		lexer_next(lexer);
	}

	lexer_next(lexer);

	return set_token(TOKEN_STRING, value);
}


Token * lexer_getChar(Lexer * lexer)
{
    lexer_next(lexer);

	char * value = calloc(1, sizeof(char));
	value[0] = '\0';

	char * s = charToString(lexer->currentChar);
	value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
	strcat(value, s);
	lexer_next(lexer);

	return set_token(TOKEN_CHAR, value);
}


Token * lexer_getId(Lexer * lexer)
{
    char * value = calloc(1, sizeof(char));
	value[0] = '\0';

	while (isalnum(lexer->currentChar))
	{
		char * s = charToString(lexer->currentChar);
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_next(lexer);
	}

    if (strcmp(value, "void") == 0)
		return set_token(TOKEN_ID_VOID, "void");

    if (strcmp(value, "bool") == 0)
		return set_token(TOKEN_ID_BOOL, "bool");

    if (strcmp(value, "short") == 0)
		return set_token(TOKEN_ID_SHORT, "short");

	if (strcmp(value, "int") == 0)
		return set_token(TOKEN_ID_INT, "int");

    if (strcmp(value, "long") == 0)
		return set_token(TOKEN_ID_LONG, "float");

	if (strcmp(value, "float") == 0)
		return set_token(TOKEN_ID_FLOAT, "float");
    
    if (strcmp(value, "double") == 0)
		return set_token(TOKEN_ID_DOUBLE, "double");

	if (strcmp(value, "char") == 0)
		return set_token(TOKEN_ID_CHAR, "char");
    
    if (strcmp(value, "ushort") == 0)
		return set_token(TOKEN_ID_USHORT, "ushort");

	if (strcmp(value, "uint") == 0)
		return set_token(TOKEN_ID_UINT, "uint");

    if (strcmp(value, "ulong") == 0)
		return set_token(TOKEN_ID_ULONG, "ulong");

	if (strcmp(value, "uchar") == 0)
		return set_token(TOKEN_ID_UCHAR, "uchar");

	if (strcmp(value, "string") == 0)
		return set_token(TOKEN_ID_STRING, "string");
    
    if (strcmp(value, "new") == 0)
		return set_token(TOKEN_ID_NEW, "new");

	if (strcmp(value, "return") == 0)
		return set_token(TOKEN_ID_RETURN, "return");
	
	return set_token(TOKEN_ID, value);
}


Token * lexer_getNumber(Lexer * lexer)
{
    char * value = calloc(1, sizeof(char));
	value[0] = '\0';
	while (isdigit(lexer->currentChar))
	{
		char * s = charToString(lexer->currentChar);
		value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_next(lexer);

		if (lexer->currentChar == '.')
		{
			char * s = charToString(lexer->currentChar);
			value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
			strcat(value, s);
			lexer_next(lexer);
			while (isdigit(lexer->currentChar))
			{
				char * s = charToString(lexer->currentChar);
				value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
				strcat(value, s);
				lexer_next(lexer);
			}
			return set_token(TOKEN_FLOAT, value);
		}
	}
	
	return set_token(TOKEN_INT, value);
}
