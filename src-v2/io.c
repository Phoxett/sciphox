#include "../include-v2/io.h"
#include <stdlib.h>


char * read_file(char * filepath)
{
    char * content;
	int length;
    int read_length;


	FILE* file = fopen(filepath, "rb");

	if (file)
	{
		fseek(file, 0, SEEK_END);
		length = ftell(file);
		fseek(file, 0, SEEK_SET);

		content = malloc(length + 1);

		if (content)
			read_length = fread(content, 1, length, file);
            if (length != read_length)
            {
                free(content);
                printf("FileError: error reading file '%s'", filepath);
                exit(1);
            }

        content[length] = '\0';
		fclose(file);
		return content;
	}
    else
    {
        printf("FileError: file '%s' does not exist", filepath);
        exit(1);
    }
}