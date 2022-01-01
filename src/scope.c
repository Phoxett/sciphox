#include "../include/scope.h"
#include <string.h>


Scope * init_scope()
{
	Scope * scope = calloc(1, sizeof(struct SCOPE));

	scope->function_definitions = (void*) 0;
	scope->function_definitions_size = 0;

	scope->variable_definitions = (void*) 0;
	scope->variable_definitions_size = 0;

	return scope;
}

Ast * scope_add_function_definition(Scope * scope, Ast * fdef)
{
	scope->function_definitions_size += 1;

	if (scope->function_definitions == (void*)0)
	{
		scope->function_definitions = calloc(1, sizeof(struct AST *));
	}
	else
	{
		scope->function_definitions =
			realloc(
				scope->function_definitions,
				scope->function_definitions_size * sizeof(struct AST **)
			);
	}

	scope->function_definitions[scope->function_definitions_size-1] =
		fdef;

	return fdef;
}

Ast * scope_get_function_definition(Scope * scope, const char * fname)
{
	for (int i = 0; i < scope->function_definitions_size; i++)
	{
		Ast * fdef = scope->function_definitions[i];

		if (strcmp(fdef->function_definition_name, fname) == 0)
		{
			return fdef;
		}
	}

	return (void*)0;
}

Ast * scope_add_variable_definition(Scope * scope, Ast * vdef)
{
	if (scope->variable_definitions == (void*) 0)
	{
		scope->variable_definitions = calloc(1, sizeof(struct AST *));
		scope->variable_definitions[0] = vdef;
		scope->variable_definitions_size += 1;
	}
	else
	{
		scope->variable_definitions_size += 1;
		scope->variable_definitions = realloc(
			scope->variable_definitions,
			scope->variable_definitions_size * sizeof(struct AST *)  
		);
		scope->variable_definitions[scope->variable_definitions_size-1] = vdef;
	}

	return vdef;
}

Ast * scope_get_variable_definition(Scope * scope, const char * name)
{
	for (int i = 0; i < scope->variable_definitions_size; i++)
	{
		Ast * vdef = scope->variable_definitions[i];

		if (strcmp(vdef->variable_definition_variable_name, name) == 0)
		{
			return vdef;
		}
	}

	return (void*)0;
}
