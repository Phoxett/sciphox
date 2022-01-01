#ifndef ERROR_H
#define ERROR_H


typedef struct ERROR
{
    enum 
    {
        SyntaxError, NameError, ZeroDivisionError, FileError
    } type;
    char * filepath;
    char * message;
    char points[1];
} Error;


void init_error(Error * error);


#endif
