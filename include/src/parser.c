#include "../include/parser.h"
#include "../include/scope.h"
#include <stdio.h>
#include <string.h>


Parser * init_parser(Lexer * lexer)
{
	Parser * parser = calloc(1, sizeof(struct PARSER));
	parser->lexer = lexer;
	parser->currentToken = lexer_getNextToken(lexer);
	parser->prevToken = parser->currentToken;

	parser->scope = init_scope();

	return parser;
}

void parser_eat(Parser * parser, int token_type)
{
	if (parser->currentToken->type == token_type)
	{
		parser->prevToken = parser->currentToken;
		parser->currentToken = lexer_getNextToken(parser->lexer);
	}
	else
	{
		printf(
			"Unexpected token `%s`, with type %d",
			parser->currentToken->value,
			parser->currentToken->type
		);
		exit(1);
	}
}

Ast * parser_parse(Parser * parser, Scope * scope)
{
	return parser_parse_statements(parser, scope);
}

Ast * parser_parse_statement(Parser * parser, Scope * scope)
{
	switch (parser->currentToken->type)
	{
		case TOKEN_ID: return parser_parse_id(parser, scope);
	}

	return init_ast(AST_NOOP);
}

Ast * parser_parse_statements(Parser * parser, Scope * scope)
{
	Ast * compound = init_ast(AST_COMPOUND);
	compound->scope = scope;
	compound->compound_value = calloc(1, sizeof(struct AST *));

	Ast * ast_statement = parser_parse_statement(parser, scope);
	ast_statement->scope = scope;
	compound->compound_value[0] = ast_statement;
	compound->compound_size += 1;

	while (parser->currentToken->type == TOKEN_SEMI)
	{
		parser_eat(parser, TOKEN_SEMI);

		Ast * ast_statement = parser_parse_statement(parser, scope);

		if (ast_statement)
		{
			compound->compound_size += 1;
			compound->compound_value = realloc(
				compound->compound_value,
				compound->compound_size * sizeof(struct AST *)
			);
			compound->compound_value[compound->compound_size-1] = ast_statement;
		}
	}

	return compound;
}

Ast * parser_parse_expr(Parser * parser, Scope * scope)
{
	switch (parser->currentToken->type)
	{
		case TOKEN_STRING: return parser_parse_string(parser, scope);
		case TOKEN_ID: return parser_parse_id(parser, scope);
	}

	return init_ast(AST_NOOP);
}

Ast * parser_parse_factor(Parser * parser, Scope * scope)
{
}

Ast * parser_parse_term(Parser * parser, Scope * scope)
{
}

Ast * parser_parse_function_call(Parser * parser, Scope * scope)
{
	Ast * function_call = init_ast(AST_FUNCTION_CALL);

	function_call->function_call_name = parser->prevToken->value;
	parser_eat(parser, TOKEN_LPAREN); 

	function_call->function_call_arguments = calloc(1, sizeof(struct AST *));

	Ast * ast_expr = parser_parse_expr(parser, scope);
	function_call->function_call_arguments[0] = ast_expr;
	function_call->function_call_arguments_size += 1;

	while (parser->currentToken->type == TOKEN_COMMA)
	{
		parser_eat(parser, TOKEN_COMMA);

		Ast * ast_expr = parser_parse_expr(parser, scope);
		function_call->function_call_arguments_size += 1;
		function_call->function_call_arguments = realloc(
			function_call->function_call_arguments,
			function_call->function_call_arguments_size * sizeof(struct AST *)
		);
		function_call->function_call_arguments[function_call->function_call_arguments_size-1] = ast_expr;
	}
	parser_eat(parser, TOKEN_RPAREN);

	function_call->scope = scope;

	return function_call;
}

Ast * parser_parse_variable_definition(Parser * parser, Scope * scope)
{
	parser_eat(parser, TOKEN_ID); // var
	char * variable_definition_variable_name = parser->currentToken->value;
	parser_eat(parser, TOKEN_ID); // var name
	parser_eat(parser, TOKEN_EQUALS);
	Ast * variable_definition_value = parser_parse_expr(parser, scope);

	Ast * variable_definition = init_ast(AST_VARIABLE_DEFINITION);
	variable_definition->variable_definition_variable_name = variable_definition_variable_name;
	variable_definition->variable_definition_value = variable_definition_value;

	variable_definition->scope = scope;

	return variable_definition;
}

Ast * parser_parse_function_definition(Parser * parser, Scope * scope)
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

Ast * parser_parse_variable(Parser * parser, Scope * scope)
{
	char * token_value = parser->currentToken->value;
	parser_eat(parser, TOKEN_ID); // var name or function call name

	if (parser->currentToken->type == TOKEN_LPAREN)
		return parser_parse_function_call(parser, scope);

	Ast * ast_variable = init_ast(AST_VARIABLE);
	ast_variable->variable_name = token_value;

	ast_variable->scope = scope;

	return ast_variable;
}

Ast * parser_parse_string(Parser * parser, Scope * scope)
{
	Ast * ast_string = init_ast(AST_STRING);
	ast_string->string_value = parser->currentToken->value;

	parser_eat(parser, TOKEN_STRING);

	ast_string->scope = scope;

	return ast_string;
}

Ast * parser_parse_id(Parser * parser, Scope * scope)
{
	if (strcmp(parser->currentToken->value, "var") == 0)
	{
		return parser_parse_variable_definition(parser, scope);
	}
	else
	if (strcmp(parser->currentToken->value, "function") == 0)
	{
		return parser_parse_function_definition(parser, scope);
	}
	else
	{
		return parser_parse_variable(parser, scope);
	}
}
