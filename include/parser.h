#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include "AST.h"
#include "scope.h"


typedef struct PARSER
{
	Lexer * lexer;
	Token * currentToken;
	Token * prevToken;
	Scope * scope;
} Parser;

Parser * init_parser(Lexer * lexer);

void parser_process(Parser * parser, int token_type);

Ast * parser_parse(Parser * parser, Scope * scope);

Ast * parser_parse_statement(Parser * parser, Scope * scope);

Ast * parser_parse_statements(Parser * parser, Scope * scope);

Ast * parser_parseExpression(Parser * parser, Scope * scope);


Ast * parser_parseFunctionCall(Parser * parser, Scope * scope);
		
Ast * parser_parse_variable_definition(Parser * parser, Scope * scope);

Ast * parser_parseIntVariableDefinition(Parser * parser, Scope * scope);
Ast * parser_parseFloatVariableDefinition(Parser * parser, Scope * scope);
Ast * parser_parseCharVariableDefinition(Parser * parser, Scope * scope);
Ast * parser_parseStringVariableDefinition(Parser * parser, Scope * scope);

Ast * parser_parse_function_definition(Parser * parser, Scope * scope);

Ast * parser_parseIntFunctionDefinition(Parser * parser, Scope * scope);
Ast * parser_parseFloatFunctionDefinition(Parser * parser, Scope * scope);
Ast * parser_parseCharFunctionDefinition(Parser * parser, Scope * scope);
Ast * parser_parseStringFunctionDefinition(Parser * parser, Scope * scope);


Ast * parser_parse_variable(Parser * parser, Scope * scope);

Ast * parser_parseString(Parser * parser, Scope * scope);
Ast * parser_parseChar(Parser * parser, Scope * scope)

Ast * parser_parseId(Parser * parser, Scope * scope);


float parser_factor(Parser * parser);
float parser_term(Parser * parser);
float parser_expression(Parser * parser);
Ast * parser_expression_ast(Parser * parser, Scope * scope);


#endif
