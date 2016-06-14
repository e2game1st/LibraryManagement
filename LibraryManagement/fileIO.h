#ifndef  __FILEIO_H__
#define __FILEIO_H__

#include "LibraryManagement.h"

#define OPEN_SUCCEED	0
#define OPEN_FAIL		-1
#define NOFILE			-2
#define FILENAME_NULL	-3

FILE* fileOpen(const char *fileName, const char *mode);


#endif // ! __FILEIO_H__
