#include "input.h"

//< 숫자입력
int inputNumber(void)
{
	int input;
	while (TRUE)
	{
		if (scanf_s("%d", &input) != 1)
		{
			puts("입력오류");
			system("pause");
			while (getchar() != '\n');
		}
		else break;
	}

	return input;
}

//< 문자 입력
char inputChar(void)
{
	char input;

	while (TRUE)
	{
		if (scanf_s("%c", &input, (int)sizeof(input)) != 1)
		{
			puts("입력오류");
			system("pause");
			while (getchar() != '\n');
		}
		else break;
	}

	return input;
}

//< 문자열 입력
char* inputString(char *str)
{
	char temp[MAX_LENGTH];

	while (TRUE)
	{
		if (scanf_s("%s", temp, (int)sizeof(temp)) != 1)
		{
			puts("입력오류");
			system("pause");
			while (getchar() != '\n');
		}
		else break;
	}

	strcpy_s(str, MAX_LENGTH, temp);
	return str;
}