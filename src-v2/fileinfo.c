#include "../include-v2/fileinfo.h"
#include <stdlib.h>


FileInfo * set_fileinfo(bool type, char * filepath)
{
	FileInfo * fileInfo = calloc(1, sizeof(FileInfo));
	fileInfo->type = type;
	fileInfo->filepath = filepath;
	return fileInfo;
}
