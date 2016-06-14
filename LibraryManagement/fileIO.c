#include "fileIO.h"

//< 파일열기
FILE* fileOpen(const char *fileName, const char *mode)
{
	//< 열기
	FILE *fp = NULL;

	//< 파일이름체크
	if (fileName == NULL)
	{
		printf("errorcode : %d\n", FILENAME_NULL);
		puts("error : file name is Nullptr");
		return NULL;
	}
	//< 오픈체크
	if ((fp = _fsopen(fileName, mode, _SH_DENYNO)) == NULL)
	{
		printf("errorcode : %d\n", OPEN_FAIL);
		printf("error : %s file open failed\n", fileName);
		return NULL;
	}

	return fp;
}