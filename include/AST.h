#ifndef AST_H
#define AST_H
#include <stdlib.h>

typedef struct AST
{
	enum astType
	{
		AST_INT_VARIABLE_DEFINITION, AST_FLOAT_VARIABLE_DEFINITION, AST_CHAR_VARIABLE_DEFINITION, AST_STRING_VARIABLE_DEFINITION,
		AST_INT_FUNCTION_DEFINITION, AST_FLOAT_FUNCTION_DEFINITION, AST_CHAR_FUNCTION_DEFINITION, AST_STRING_FUNCTION_DEFINITION,
		AST_VARIABLE_DEFINITION,
		AST_FUNCTION_DEFINITION,
		AST_VARIABLE,
		AST_FUNCTION_CALL,
		AST_INT, AST_FLOAT, AST_CHAR,AST_STRING,
		AST_COMPOUND,
		AST_NOOP
	} type;

	struct SCOPE * scope;

	/* AST_VARIABLE_DEFINITION */
	char * variable_definition_variable_name;
	struct AST * variable_definition_value;
	
	/* VARIABLE DEFINITION */
	
	char * variable_def_name;
	char variable_def_type;
	struct AST * variable_def_value;
	
	/* AST VALUES */
	
	int int_value;
	float float_value;
	char char_value;
	char * string_value;
	
	/* AST_FUNCTION_DEFINITION */
	struct AST * function_definition_body;
	char * function_definition_name;
	struct AST ** function_definition_args;
	size_t function_definition_args_size;

	/* AST_VARIABLE */
	char * variable_name;

	/* AST_FUNCTION_CALL */
	char * function_call_name;
	struct AST ** function_call_arguments;
	size_t function_call_arguments_size;

	/* AST_COMPOUND */
	struct AST ** compound_value;
	size_t compound_size;
} Ast;

Ast * init_ast(char type);
#endif
