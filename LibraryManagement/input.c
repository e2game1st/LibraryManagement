#include "input.h"

//< �����Է�
int inputNumber(void)
{
	int input;
	while (TRUE)
	{
		if (scanf_s("%d", &input) != 1)
		{
			puts("�Է¿���");
			system("pause");
			while (getchar() != '\n');
		}
		else break;
	}

	return input;
}

//< ���� �Է�
char inputChar(void)
{
	char input;

	while (TRUE)
	{
		if (scanf_s("%c", &input, (int)sizeof(input)) != 1)
		{
			puts("�Է¿���");
			system("pause");
			while (getchar() != '\n');
		}
		else break;
	}

	return input;
}

//< ���ڿ� �Է�
char* inputString(char *str)
{
	char temp[MAX_LENGTH];

	while (TRUE)
	{
		if (scanf_s("%s", temp, (int)sizeof(temp)) != 1)
		{
			puts("�Է¿���");
			system("pause");
			while (getchar() != '\n');
		}
		else break;
	}

	strcpy_s(str, MAX_LENGTH, temp);
	return str;
}