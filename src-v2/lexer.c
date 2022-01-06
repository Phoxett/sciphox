#include "../include-v2/lexer.h"
#include "../include-v2/util.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


Lexer * set_lexer(FileInfo * fileinfo, char * content)
{
    Lexer * lexer = calloc(1, sizeof(Lexer));
    lexer->line = 1;
    lexer->column = 1;
    lexer->content = content;
    lexer->index = 0;
    lexer->currentChar = lexer->content[lexer->index];
    lexer->fileInfo = fileinfo;
    return lexer;
}


void lexer_next(Lexer * lexer)
{
    if ((lexer->currentChar != '\0') && (lexer->index < strlen(lexer->content)))
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
		lexer_next(lexer);
	}
}


void lexer_skipNewline(Lexer * lexer)
{
    while (lexer->currentChar == '\n')
	{
		lexer_next(lexer);
		lexer->column += 1;
		lexer->line += 1;
	}
}


bool lexer_peek(Lexer * lexer, char gvalue)
{
    char value = lexer->content[lexer->index + 1];
    if (value == gvalue)
    {
        return 1;
    }
    
    return 0;
}


Token * lexer_nextWithToken(Lexer * lexer, Token * token)
{
    lexer_next(lexer);
	return token;
}


Token * lexer_getNextToken(Lexer * lexer)
{
    while ((lexer->currentChar != '\0') && (lexer->index < strlen(lexer->content)))
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

		if (lexer->currentChar == '\'')
			return lexer_getChar(lexer);

        switch (lexer->currentChar)
        {
            case '=':
                return lexer_nextWithToken(lexer, set_token(TOKEN_EQUAL, charToString(lexer->currentChar)));
                break;

			case '+':
                return lexer_evaluateEqual(lexer);
                break;

			case '-':
                return lexer_evaluateEqual(lexer);
                break;

			case '*':
                return lexer_evaluateEqual(lexer);
                break;

			case '/': 
                return lexer_evaluateEqual(lexer);
                break;

			case '%':
                return lexer_evaluateEqual(lexer);
                break;

			case '^':
                return lexer_evaluateEqual(lexer);
                break;
            
			case ';':
                return lexer_nextWithToken(lexer, set_token(TOKEN_SEMI, charToString(lexer->currentChar)));
                break;

			case ':':
                return lexer_nextWithToken(lexer, set_token(TOKEN_COLON, charToString(lexer->currentChar)));
                break;

			case '(':
                return lexer_nextWithToken(lexer, set_token(TOKEN_LPAREN, charToString(lexer->currentChar)));
                break;

			case ')':
                return lexer_nextWithToken(lexer, set_token(TOKEN_RPAREN, charToString(lexer->currentChar)));
                break;

			case '{':
                return lexer_nextWithToken(lexer, set_token(TOKEN_LBRACE, charToString(lexer->currentChar)));
                break;

			case '}':
                return lexer_nextWithToken(lexer, set_token(TOKEN_RBRACE, charToString(lexer->currentChar)));
                break;

			case ',':
                return lexer_nextWithToken(lexer, set_token(TOKEN_COMMA, charToString(lexer->currentChar)));
                break;

			case '.':
                return lexer_nextWithToken(lexer, set_token(TOKEN_FULLSTOP, charToString(lexer->currentChar)));
                break;
        }
    }
}
