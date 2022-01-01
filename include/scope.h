#ifndef SCOPE_H
#define SCOPE_H


#include "AST.h"

typedef struct SCOPE
{
	Ast ** function_definitions;
	size_t function_definitions_size;

	Ast ** variable_definitions;
	size_t variable_definitions_size;
} Scope;

Scope * init_scope();

Ast * scope_add_function_definition(Scope * scope, Ast * fdef);

Ast * scope_get_function_definition(Scope * scope, const char * fname);

Ast * scope_add_variable_definition(Scope * scope, Ast * vdef);

Ast * scope_get_variable_definition(Scope * scope, const char * name);


#endif
