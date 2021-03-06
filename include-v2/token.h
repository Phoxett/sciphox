#ifndef TOKEN_H
#define TOKEN_H


typedef struct TOKEN
{
	enum tokenType
	{
		TOKEN_ID,
		TOKEN_ID_NEW, TOKEN_ID_RETURN,
		TOKEN_ID_FOR, TOKEN_ID_WHILE,
		TOKEN_ID_IF, TOKEN_ID_ELIF, TOKEN_ID_ELSE,
		TOKEN_ID_OR, TOKEN_ID_AND, TOKEN_ID_NOR,
		TOKEN_ID_BOOL, TOKEN_ID_VOID,
		TOKEN_ID_CHAR, TOKEN_ID_SHORT, TOKEN_ID_INT, TOKEN_ID_LONG, TOKEN_ID_FLOAT, TOKEN_ID_DOUBLE, TOKEN_ID_STRING,
		TOKEN_ID_UCHAR, TOKEN_ID_USHORT, TOKEN_ID_UINT, TOKEN_ID_ULONG,
		TOKEN_PLUS, TOKEN_MINUS, TOKEN_MUL, TOKEN_DIV, TOKEN_MOD, TOKEN_POW,
		TOKEN_PLUS_EQUAL, TOKEN_MINUS_EQUAL, TOKEN_MUL_EQUAL, TOKEN_DIV_EQUAL, TOKEN_MOD_EQUAL, TOKEN_POW_EQUAL,
		TOKEN_GTHAN, TOKEN_LTHAN, TOKEN_EQUAL,
		TOKEN_GTHAN_EQUAL, TOKEN_LTHAN_EQUAL,
		TOKEN_COMMA, TOKEN_FULLSTOP, TOKEN_SEMI, TOKEN_COLON,
		TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_LBRACE, TOKEN_RBRACE,
		TOKEN_INT, TOKEN_FLOAT, TOKEN_CHAR, TOKEN_STRING
	} type;
	char * value;
} Token;


Token * set_token(char type, char * value);


#endif
