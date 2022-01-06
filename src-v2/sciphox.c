#include "../include-v2/lexer.h"
#include "../include-v2/io.h"
#include <string.h>
#include <stdio.h>


int main(int argc, char * argv[])
{
	char * content = read_file(argv[1]);
	FileInfo * fileinfo = set_fileinfo(FILEINFO_SPL, argv[1]);
	Lexer * lexer = set_lexer(fileinfo, content);
	while ((lexer->currentChar != '\0') && (lexer->index < strlen(lexer->content)))
	{
		Token * token = lexer_getNextToken(lexer);
		printf("[%d\t: %s\n", token->type, token->value);
	}
	return 0;
}