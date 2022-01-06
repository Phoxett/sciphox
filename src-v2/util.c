#include "../include-v2/util.h"
#include <stdlib.h>


char * charToString(char value)
{
    char * string = calloc(2, sizeof(char));
	string[0] = value;
	string[1] = '\0';
	return string;
}
