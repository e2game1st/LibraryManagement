#include "fileIO.h"

//< ���Ͽ���
FILE* fileOpen(const char *fileName, const char *mode)
{
	//< ����
	FILE *fp = NULL;

	//< �����̸�üũ
	if (fileName == NULL)
	{
		printf("errorcode : %d\n", FILENAME_NULL);
		puts("error : file name is Nullptr");
		return NULL;
	}
	//< ����üũ
	if ((fp = _fsopen(fileName, mode, _SH_DENYNO)) == NULL)
	{
		printf("errorcode : %d\n", OPEN_FAIL);
		printf("error : %s file open failed\n", fileName);
		return NULL;
	}

	return fp;
}