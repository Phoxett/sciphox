#include "../include/parser.h"
#include <stdbool.h>


bool check_NextToken(Parser * parser, char type)
{
	if (parser->currentToken->type == type)
	{
		return true;
	}
	
	return false;
}
