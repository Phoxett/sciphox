#ifndef TOKEN_H
#define TOKEN_H


typedef struct TOKEN
{
	enum tokenType
	{
		TOKEN_ID, TOKEN_NEW_ID, TOKEN_RETURN_ID, TOKEN_INT_ID, TOKEN_FLOAT_ID, TOKEN_CHAR_ID, TOKEN_STRING_ID,
		TOKEN_EQUALS, TOKEN_PLUS, TOKEN_MINUS, TOKEN_MUL, TOKEN_DIV, TOKEN_MOD, TOKEN_POW,
		TOKEN_INT, TOKEN_FLOAT, TOKEN_CHAR, TOKEN_STRING,
		TOKEN_COLON, TOKEN_SEMI,
		TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_RBRACE, TOKEN_LBRACE,
		TOKEN_COMMA, TOKEN_FULLSTOP,
		TOKEN_EOF
	} type;
	char * value;
} Token;


Token * init_token(char type, char * value);


#endif
