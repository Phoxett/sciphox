#include "../include/token.h"
#include <stdlib.h>


Token * set_token(char type, char * value)
{
	Token * token = calloc(1, sizeof(Token));
	token->type = type;
	token->value = value;
	return token;
}
