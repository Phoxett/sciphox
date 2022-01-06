#include "../include-v2/ast.h"
#include <stdlib.h>


Ast * init_ast(char type)
{
    Ast * ast = calloc(1, sizeof(Ast));

    /* AST VALUES */

    ast->type = type;
    ast->value_bool = 0;
    ast->value_short = 0;
    ast->value_int = 0;
    ast->value_long = 0;
    ast->value_char = 0;
    ast->value_float = 0.0;
    ast->value_double = 0.0;
    ast->value_ushort = 0;
    ast->value_uint = 0;
    ast->value_ulong = 0;
    ast->value_uchar = 0;

    /* AST VARIABLE */

	ast->variable_name = "";

    /* AST FUNCTION CALL */

    ast->function_call_name = "";
	ast->function_call_arguments = (void*) 0;
	ast->function_call_arguments_size = 0;

    /* AST FUNCTION DEFINITION */
	
    ast->function_definition_type = 0;
	ast->function_definition_name = "";
    ast->function_definition_body = (void*) 0;
	ast->function_definition_args = (void*) 0;
	ast->function_definition_args_size = 0;

    /* AST COMPOUND */
	
    ast->compound_body = (void*) 0;
	ast->compound_size = 0;
    return ast;
}
