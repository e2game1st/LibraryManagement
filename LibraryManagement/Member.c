#include "member.h"

//< ���� ����
void checkFile(void)
{
	FILE *fp = NULL, *fp2 = NULL;

	//< ���� ����
	if (((fp = fileOpen("index.txt", "r")) == NULL)
		|| ((fp2 = fileOpen("index.txt", "r")) == NULL))
	{
		//< ���Ͽ��� üũ
		makeFile();
	}
	else
	{
		fclose(fp);
		fclose(fp2);
	}
}

//< ȸ��
void registrator(void)
{
	//< �Է�Ŀ�ǵ�
	int inputCommand;
	while (TRUE)
	{
		//< ȭ�������
		system("cls");
		//< �޴����
		menuOutput();
		//< �Է�
		inputCommand = inputNumber();
		//< �б�ó��
		switch (inputCommand)
		{
		case  END: { system("pause"); return; }
		case  REGESTRATION: { registrationMember(); }break;
		case  SEARCHMEMBER: { searchMember(); }break;
		case  OUTPUTMEMBER: { memberOutput(); }break;
		default: { system("pause"); return; }break;
		}
	}
}