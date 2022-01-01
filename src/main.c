#include "../include/parser.h"
#include <string.h>
#include <stdio.h>


int main()

{
    char * content = "int age = 10.787+10-5.5:";
    Lexer * lexer = init_lexer(content);
	Parser * parser = init_parser(lexer);
	parser_process(parser, TOKEN_INT_ID);
	parser_process(parser, TOKEN_ID);
	parser_process(parser, TOKEN_EQUALS);
	float res = parser_expression(parser);
	printf("text: %s\nans: %g\n", content, res);
    return 0;
}