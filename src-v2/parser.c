#include "../include-v2/parser.h"
#include <stdlib.h>


Parser * set_parser(Lexer * lexer)
{
    Parser * parser = calloc(1, sizeof(Parser));
    parser->lexer = lexer;
    parser->currentToken = lexer_getNextToken(lexer);
	parser->previousToken = parser->currentToken;
    return parser;
}
