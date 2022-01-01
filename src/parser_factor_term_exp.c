#include "../include/parser.h"
#include "../include/util.h"
#include <stdio.h>


float parser_factor(Parser * parser)
{
	float result;
	Token * token = parser->currentToken;
	switch (token->type)
	{
		case TOKEN_INT:
			parser_process(parser, TOKEN_INT);
			return atof(token->value);
		case TOKEN_FLOAT:
			parser_process(parser, TOKEN_FLOAT);
			return atof(token->value);
		case TOKEN_LPAREN:
			parser_process(parser, TOKEN_LPAREN);
			result = parser_expression(parser);
			parser_process(parser, TOKEN_RPAREN);
			return result;
	}
}


float parser_term(Parser * parser)
{
	float result = parser_factor(parser);

	while ((parser->currentToken->type == TOKEN_MUL) || (parser->currentToken->type == TOKEN_DIV))
	{
		Token * token = parser->currentToken;
		switch (token->type)
		{
			case TOKEN_DIV:
				parser_process(parser, TOKEN_DIV);
				result /= parser_factor(parser);
				break;
			case TOKEN_MUL:
				parser_process(parser, TOKEN_MUL);
				result *= parser_factor(parser);
				break;
		}
	}

	return result;
}


float parser_expression(Parser * parser)
{
	float result = parser_term(parser);

	while ((parser->currentToken->type == TOKEN_PLUS) || (parser->currentToken->type == TOKEN_MINUS))
	{
		Token * token = parser->currentToken;
		switch (token->type)
		{
			case TOKEN_PLUS:
				parser_process(parser, TOKEN_PLUS);
				result += parser_term(parser);
				break;
			case TOKEN_MINUS:
				parser_process(parser, TOKEN_MINUS);
				result -= parser_term(parser);
				break;
		}
	}

	return result;
}


Ast * parser_expression_ast(Parser * parser, Scope * scope)
{
	float result = parser_expression(parser);

	if (check_isItInt(result))
		{
			Ast * ast_int = init_ast(AST_INT);
			ast_int->int_value = (int) result;
			parser_process(parser, TOKEN_INT);
			ast_int->scope = scope;
			return ast_int;
		}

		Ast * ast_float = init_ast(AST_FLOAT);
		ast_float->float_value = result;
		parser_process(parser, TOKEN_INT);
		ast_float->scope = scope;
		return ast_float;
}