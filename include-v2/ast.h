#ifndef AST_H
#define AST_H


#include <stdbool.h>
#include <stddef.h>


typedef struct AST
{
    enum astType
    {
        AST_BOOL_VARIABLE_DEFINITION, AST_SHORT_VARIABLE_DEFINITION, AST_INT_VARIABLE_DEFINITION, AST_LONG_VARIABLE_DEFINITION, AST_CHAR_VARIABLE_DEFINITION, AST_FLOAT_VARIABLE_DEFINITION, AST_DOUBLE_VARIABLE_DEFINITION,
        AST_USHORT_VARIABLE_DEFINITION, AST_UINT_VARIABLE_DEFINITION, AST_ULONG_VARIABLE_DEFINITION, AST_UCHAR_VARIABLE_DEFINITION,
        AST_BOOL_FUNCTIOn_DEFINITION, AST_SHORT_FUNCTIOn_DEFINITION, AST_INT_FUNCTIOn_DEFINITION, AST_LONG_FUNCTIOn_DEFINITION, AST_CHAR_FUNCTIOn_DEFINITION, AST_FLOAT_FUNCTIOn_DEFINITION, AST_DOUBLE_FUNCTIOn_DEFINITION,
        AST_USHORT_FUNCTIOn_DEFINITION, AST_UINT_FUNCTIOn_DEFINITION, AST_ULONG_FUNCTIOn_DEFINITION, AST_UCHAR_FUNCTIOn_DEFINITION,
        AST_BOOL, AST_SHORT, AST_INT, AST_LONG, AST_CHAR, AST_FLOAT, AST_DOUBLE,
        AST_USHORT, AST_UINT, AST_ULONG, AST_UCHAR,
        AST_VARIABLE,
        AST_FUNCTION_CALL,
        AST_COMPOUND,
        AST_NOOD
    } type;

    /* AST VALUES */

    bool value_bool;
    short value_short;
    int value_int;
    long value_long;
    char value_char;
    float value_float;
    double value_double;
    unsigned short value_ushort;
    unsigned int value_uint;
    unsigned long value_ulong;
    unsigned char value_uchar;

    /* AST VARIABLE */

	char * variable_name;

    /* AST FUNCTION CALL */

    char * function_call_name;
	struct AST ** function_call_arguments;
	size_t function_call_arguments_size;

    /* AST FUNCTION DEFINITION */
	
    char function_definition_type;
	char * function_definition_name;
    struct AST * function_definition_body;
	struct AST ** function_definition_args;
	size_t function_definition_args_size;

    /* AST COMPOUND */
	
    struct AST ** compound_body;
	size_t compound_size;
} Ast;


Ast * set_ast(char type);


#endif
