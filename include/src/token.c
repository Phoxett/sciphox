#include "../include/token.h"
#include <stdlib.h>


Token * init_token(char type, char * value)
{
	Token * token = calloc(1, sizeof(struct TOKEN));
	token->type = type;
	token->value = value;

	return token;
}
