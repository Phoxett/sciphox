#include "../include/parser.h"
#include "../include/util.h"
#include <math.h>


bool check_NextToken(Parser * parser, char type)
{
	if (parser->currentToken->type == type)
	{
		return true;
	}
	
	return false;
}


bool check_isItInt(float value)
{
	return (fabsf(roundf(value) - value) <= 0.00001f);
}