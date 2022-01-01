#include "../include/parser.h"
#include "../include/util.h"


Ast * parser_parseIntVariableDefinition(Parser * parser, Scope * scope)
{
	parser_eat(parser, TOKEN_ID); // int
	char * variable_def_name = parser->currentToken->value;
	parser_eat(parser, TOKEN_ID); // name
	if (check_NextToken(parser, TOKEN_EQUALS))
	{
		parser_eat(parser, TOKEN_EQUALS);
		Ast * variable_def_value = parser_parse_expr(parser, scope);
		Ast * variable_def = init_ast(AST_INT_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_INT_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	else if (check_NextToken(parser, TOKEN_COLON))
	{
		
		Ast * variable_def_value = init_ast(AST_INT);
		variable_def_value->int_value = 0;
		Ast * variable_def = init_ast(AST_INT_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_INT_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	else if (check_NextToken(parser, TOKEN_COMMA))
	{
		Ast * variable_def_value = init_ast(AST_INT);
		variable_def_value->int_value = 0;
		Ast * variable_def = init_ast(AST_INT_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_INT_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	printf(
		"SyntaxError: unexpected token %s (expected ':' or ','), [ln %d, col %d]",
		parser->currentToken->value,
		parser->lexer->line,
		parser->lexer->column);
	exit(1);
}


Ast * parser_parseFloatVariableDefinition(Parser * parser, Scope * scope)
{
	parser_eat(parser, TOKEN_ID); // float
	char * variable_def_name = parser->currentToken->value;
	parser_eat(parser, TOKEN_ID); // name
	if (check_NextToken(parser, TOKEN_EQUALS))
	{
		parser_eat(parser, TOKEN_EQUALS);
		Ast * variable_def_value = parser_parse_expr(parser, scope);
		Ast * variable_def = init_ast(AST_FLOAT_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_FLOAT_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	else if (check_NextToken(parser, TOKEN_COLON))
	{
		
		Ast * variable_def_value = init_ast(AST_FLOAT);
		variable_def_value->float_value = 0.0;
		Ast * variable_def = init_ast(AST_FLOAT_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_FLOAT_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	else if (check_NextToken(parser, TOKEN_COMMA))
	{
		Ast * variable_def_value = init_ast(AST_FLOAT);
		variable_def_value->float_value = 0.0;
		Ast * variable_def = init_ast(AST_FLOAT_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_FLOAT_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	
	printf(
		"SyntaxError: unexpected token %s (expected ':' or ','), [ln %d, col %d]",
		parser->currentToken->value,
		parser->lexer->line,
		parser->lexer->column);
	exit(1);
}


Ast * parser_parseCharVariableDefinition(Parser * parser, Scope * scope)
{
	parser_eat(parser, TOKEN_ID); // char
	char * variable_def_name = parser->currentToken->value;
	parser_eat(parser, TOKEN_ID); // name
	if (check_NextToken(parser, TOKEN_EQUALS))
	{
		parser_eat(parser, TOKEN_EQUALS);
		Ast * variable_def_value = parser_parse_expr(parser, scope);
		Ast * variable_def = init_ast(AST_CHAR_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_CHAR_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	else if (check_NextToken(parser, TOKEN_COLON))
	{
		
		Ast * variable_def_value = init_ast(AST_CHAR);
		variable_def_value->char_value = '\0';
		Ast * variable_def = init_ast(AST_CHAR_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_CHAR_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	else if (check_NextToken(parser, TOKEN_COMMA))
	{
		Ast * variable_def_value = init_ast(AST_CHAR);
		variable_def_value->char_value = '\0';
		Ast * variable_def = init_ast(AST_CHAR_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_CHAR_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	printf(
		"SyntaxError: unexpected token %s (expected ':' or ','), [ln %d, col %d]",
		parser->currentToken->value,
		parser->lexer->line,
		parser->lexer->column);
	exit(1);
}


Ast * parser_parseStringVariableDefinition(Parser * parser, Scope * scope)
{
	parser_eat(parser, TOKEN_ID); // int
	char * variable_def_name = parser->currentToken->value;
	parser_eat(parser, TOKEN_ID); // name
	if (check_NextToken(parser, TOKEN_EQUALS))
	{
		parser_eat(parser, TOKEN_EQUALS);
		Ast * variable_def_value = parser_parse_expr(parser, scope);
		Ast * variable_def = init_ast(AST_STRING_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_STRING_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	else if (check_NextToken(parser, TOKEN_COLON))
	{
		
		Ast * variable_def_value = init_ast(AST_INT);
		variable_def_value->string_value = "";
		Ast * variable_def = init_ast(AST_STRING_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_STRING_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	
	else if (check_NextToken(parser, TOKEN_COMMA))
	{
		Ast * variable_def_value = init_ast(AST_STRING);
		variable_def_value->string_value = "";
		Ast * variable_def = init_ast(AST_STRING_VARIABLE_DEFINITION);
		variable_def->variable_def_name = variable_def_name;
		variable_def->variable_def_type = TOKEN_STRING_ID;
		variable_def->variable_def_value = variable_def_value;
		variable_def->scope = scope;
		return variable_def;
	}
	printf(
		"SyntaxError: unexpected token %s (expected ':' or ','), [ln %d, col %d]",
		parser->currentToken->value,
		parser->lexer->line,
		parser->lexer->column);
	exit(1);
}
