#ifndef FILEINFO_H
#define FILEINFO_H


#include <stdbool.h>


typedef struct FILEINFO
{
	enum fileType
	{
		FILEINFO_PPL,
		FILEINFO_SPL
	} type;
	char * filepath;
} FileInfo;


FileInfo * set_fileinfo(bool type, char * filepath);


#endif
