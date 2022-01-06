#include "../include-v2/error.h"
#include <stdlib.h>
#include <stdio.h>


Error * set_error(char type, char status_code, char * message)
{
    Error * error = calloc(1, sizeof(Error));
    error->type = type;
    error->status_code = type;
    error->message = message;
    return error;
}


void error_print(char type, char status_code, char * message, char * extra)
{
    Error * error = set_error(type, status_code, message);
    char * error_message;
    switch (error->status_code)
    {
    case 0:
        {
            
            sprintf(
                error_message,
                "%s%s:  ", 
                ERROR_COLOUR_GREEN, 
            );
        }
    
    default:
        break;
    }
}
