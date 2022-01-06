#include "../include-v2/lexer.h"
#include "../include-v2/util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char * lexer_2charToString(Lexer * lexer)
{
    char * string = calloc(3, sizeof(char));
	string[0] = lexer->currentChar;
    lexer_next(lexer);
    string[1] = lexer->currentChar;
	string[2] = '\0';
    lexer_next(lexer);
	return string;
    

}


Token * lexer_evaluateEqual(Lexer * lexer)
{
    if ((lexer_peek(lexer, '=')) && (lexer->currentChar == '+'))
        return set_token(TOKEN_PLUS_EQUAL, lexer_2charToString(lexer));

    else if ((lexer_peek(lexer, '=')) && (lexer->currentChar == '-'))
        return set_token(TOKEN_MINUS_EQUAL, lexer_2charToString(lexer));

    else if ((lexer_peek(lexer, '=')) && (lexer->currentChar == '*'))
        return set_token(TOKEN_MUL_EQUAL, lexer_2charToString(lexer));

    else if ((lexer_peek(lexer, '=')) && (lexer->currentChar == '/'))
        return set_token(TOKEN_DIV_EQUAL, lexer_2charToString(lexer));

    else if ((lexer_peek(lexer, '=')) && (lexer->currentChar == '%'))
        return set_token(TOKEN_MOD_EQUAL, lexer_2charToString(lexer));

    else if ((lexer_peek(lexer, '=')) && (lexer->currentChar == '^'))
        return set_token(TOKEN_POW_EQUAL, lexer_2charToString(lexer));

    else
        return lexer_getNextTokenEqual(lexer);

}


Token * lexer_getNextTokenEqual(Lexer * lexer)
{
    switch (lexer->currentChar)
    {
        case '+':
            return lexer_nextWithToken(lexer, set_token(TOKEN_PLUS, charToString(lexer->currentChar)));
            break;

        case '-':
            return lexer_nextWithToken(lexer, set_token(TOKEN_MINUS, charToString(lexer->currentChar)));
            break;

        case '*':
            return lexer_nextWithToken(lexer, set_token(TOKEN_MUL, charToString(lexer->currentChar)));
            break;

        case '/': 
            return lexer_nextWithToken(lexer, set_token(TOKEN_DIV, charToString(lexer->currentChar)));
            break;

        case '%':
            return lexer_nextWithToken(lexer, set_token(TOKEN_MOD, charToString(lexer->currentChar)));
            break;

        case '^':
            return lexer_nextWithToken(lexer, set_token(TOKEN_POW, charToString(lexer->currentChar)));
            break;
    }
}
