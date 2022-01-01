#ifndef UTIL_H
#define UTIL_H


#include "parser.h"
#include <stdbool.h>


bool check_NextToken(Parser * parser, char type);
bool check_isItInt(float value);


#endif
