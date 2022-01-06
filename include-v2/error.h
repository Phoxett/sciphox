#ifndef ERROR_H
#define ERROR_H


#define ERROR_NORMAL_EXIT 0
#define ERROR_ABNORMAL_EXIT 1
#define ERROR_PROGRAM_CRASH 2
#define ERROR_COLOUR_RED "\x1B[31m"
#define ERROR_COLOUR_GREEN "\x1B[32m"
#define ERROR_COLOUR_YELLOW "\x1B[33m"
#define ERROR_COLOUR_BLUE "\x1B[34m"
#define ERROR_COLOUR_MAGENTA "\x1B[35m"
#define ERROR_COLOUR_CYAN "\x1B[36m"
#define ERROR_COLOUR_WHITE "\x1B[37m"
#define ERROR_COLOUR_RESET "\x1B[0m"


typedef struct ERROR
{
    enum
    {
        ERROR_SYNTAX_ERROR,
        ERROR_FILE_ERROR,
        ERROR_TYPE_ERROR
    } type;
    char status_code;
    char * message;
} Error;


Error * set_error(char type, char status_code, char * message);

void error_print(char type, char status_code, char * message, char * extra);


#endif
