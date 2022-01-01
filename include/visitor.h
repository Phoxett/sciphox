#ifndef VISITOR_H
#define VISITOR_H
#include "AST.h"

typedef struct VISITOR_STRUCT
{
} visitor_T;

visitor_T* init_visitor();

Ast * visitor_visit(visitor_T* visitor, Ast * node);

Ast * visitor_visit_variable_definition(visitor_T* visitor, Ast * node);

Ast * visitor_visit_function_definition(visitor_T* visitor, Ast * node);

Ast * visitor_visit_variable(visitor_T* visitor, Ast * node);

Ast * visitor_visit_function_call(visitor_T* visitor, Ast * node);

Ast * visitor_visit_string(visitor_T* visitor, Ast * node);

Ast * visitor_visit_compound(visitor_T* visitor, Ast * node);
#endif
