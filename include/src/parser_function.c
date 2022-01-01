#include "../include/parser.h"
#include <string.h>


Ast * parser_parseIntFunctionDefinition(Parser * parser, Scope * scope)
{
	Ast * ast = init_ast(AST_INT_FUNCTION_DEFINITION);
	parser_eat(parser, TOKEN_INT_ID); // int

	char * function_name = parser->currentToken->value;
	ast->function_definition_name = calloc(
			strlen(function_name) + 1,
			sizeof(char));
	strcpy(ast->function_definition_name, function_name);

	parser_eat(parser, TOKEN_ID); // function name
	parser_eat(parser, TOKEN_LPAREN);

	ast->function_definition_args = calloc(1, sizeof(struct AST *));

	Ast * arg = parser_parse_variable(parser, scope);
	ast->function_definition_args_size += 1;
	ast->function_definition_args[ast->function_definition_args_size-1] = arg;

	while (parser->currentToken->type == TOKEN_COMMA)
	{
		parser_eat(parser, TOKEN_COMMA);

		ast->function_definition_args_size += 1;

		ast->function_definition_args =
			realloc(
					ast->function_definition_args,
					ast->function_definition_args_size * sizeof(struct AST *)
				   );

		Ast * arg = parser_parse_variable(parser, scope);
		ast->function_definition_args[ast->function_definition_args_size-1] = arg;
	}

	parser_eat(parser, TOKEN_RPAREN);
	
	parser_eat(parser, TOKEN_LBRACE);
	
	ast->function_definition_body = parser_parse_statements(parser, scope);

	parser_eat(parser, TOKEN_RBRACE);

	ast->scope = scope;

	return ast;
}


Ast * parser_parseFloatFunctionDefinition(Parser * parser, Scope * scope)
{
	Ast * ast = init_ast(AST_FUNCTION_DEFINITION);
	parser_eat(parser, TOKEN_ID); // function

	char * function_name = parser->currentToken->value;
	ast->function_definition_name = calloc(
			strlen(function_name) + 1, sizeof(char)
	);
	strcpy(ast->function_definition_name, function_name);

	parser_eat(parser, TOKEN_ID); // function name

	parser_eat(parser, TOKEN_LPAREN);

	ast->function_definition_args =
		calloc(1, sizeof(struct AST *));

	Ast * arg = parser_parse_variable(parser, scope);
	ast->function_definition_args_size += 1;
	ast->function_definition_args[ast->function_definition_args_size-1] = arg;

	while (parser->currentToken->type == TOKEN_COMMA)
	{
		parser_eat(parser, TOKEN_COMMA);

		ast->function_definition_args_size += 1;

		ast->function_definition_args =
			realloc(
					ast->function_definition_args,
					ast->function_definition_args_size * sizeof(struct AST *)
				   );

		Ast * arg = parser_parse_variable(parser, scope);
		ast->function_definition_args[ast->function_definition_args_size-1] = arg;
	}

	parser_eat(parser, TOKEN_RPAREN);
	
	parser_eat(parser, TOKEN_LBRACE);
	
	ast->function_definition_body = parser_parse_statements(parser, scope);

	parser_eat(parser, TOKEN_RBRACE);

	ast->scope = scope;

	return ast;
}


Ast * parser_parseCharFunctionDefinition(Parser * parser, Scope * scope)
{
	Ast * ast = init_ast(AST_FUNCTION_DEFINITION);
	parser_eat(parser, TOKEN_ID); // function

	char * function_name = parser->currentToken->value;
	ast->function_definition_name = calloc(
			strlen(function_name) + 1, sizeof(char)
	);
	strcpy(ast->function_definition_name, function_name);

	parser_eat(parser, TOKEN_ID); // function name

	parser_eat(parser, TOKEN_LPAREN);

	ast->function_definition_args =
		calloc(1, sizeof(struct AST *));

	Ast * arg = parser_parse_variable(parser, scope);
	ast->function_definition_args_size += 1;
	ast->function_definition_args[ast->function_definition_args_size-1] = arg;

	while (parser->currentToken->type == TOKEN_COMMA)
	{
		parser_eat(parser, TOKEN_COMMA);

		ast->function_definition_args_size += 1;

		ast->function_definition_args =
			realloc(
					ast->function_definition_args,
					ast->function_definition_args_size * sizeof(struct AST *)
				   );

		Ast * arg = parser_parse_variable(parser, scope);
		ast->function_definition_args[ast->function_definition_args_size-1] = arg;
	}

	parser_eat(parser, TOKEN_RPAREN);
	
	parser_eat(parser, TOKEN_LBRACE);
	
	ast->function_definition_body = parser_parse_statements(parser, scope);

	parser_eat(parser, TOKEN_RBRACE);

	ast->scope = scope;

	return ast;
}


Ast * parser_parseStringFunctionDefinition(Parser * parser, Scope * scope)
{
	Ast * ast = init_ast(AST_FUNCTION_DEFINITION);
	parser_eat(parser, TOKEN_ID); // function

	char * function_name = parser->currentToken->value;
	ast->function_definition_name = calloc(
			strlen(function_name) + 1, sizeof(char)
	);
	strcpy(ast->function_definition_name, function_name);

	parser_eat(parser, TOKEN_ID); // function name

	parser_eat(parser, TOKEN_LPAREN);

	ast->function_definition_args =
		calloc(1, sizeof(struct AST *));

	Ast * arg = parser_parse_variable(parser, scope);
	ast->function_definition_args_size += 1;
	ast->function_definition_args[ast->function_definition_args_size-1] = arg;

	while (parser->currentToken->type == TOKEN_COMMA)
	{
		parser_eat(parser, TOKEN_COMMA);

		ast->function_definition_args_size += 1;

		ast->function_definition_args =
			realloc(
					ast->function_definition_args,
					ast->function_definition_args_size * sizeof(struct AST *)
				   );

		Ast * arg = parser_parse_variable(parser, scope);
		ast->function_definition_args[ast->function_definition_args_size-1] = arg;
	}

	parser_eat(parser, TOKEN_RPAREN);
	
	parser_eat(parser, TOKEN_LBRACE);
	
	ast->function_definition_body = parser_parse_statements(parser, scope);

	parser_eat(parser, TOKEN_RBRACE);

	ast->scope = scope;

	return ast;
}
