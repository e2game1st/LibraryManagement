#include "MemberManagement.h"


/*
1. ȸ����������

a. ȸ������
b. ȸ���˻�(�ֹι�ȣ�˻� �� 6�ڸ�������) (��ĥ�� ������)
��.ȸ������
��.ȸ������
c. ȸ���������(���ȸ������)

- ȸ������
: id, �̸�, �ּ�, �ֹι�ȣ(6�ڸ�),hp��ȣ,Email,����å

0000000000 �ڸ��� ����(10�ڸ�)
ID : ����ID����(???)(�ڵ������ϱ�) - ��������
�̸� : �ߺ�����
�ּ� : ���ڿ�����(40�ڱ����Է°���) �ѱ۱���
�ֹι�ȣ : �ߺ�����(6�� üũ���� - 000405(6�ڸ�Ȯ��)
hp��ȣ : -�� ������ ��ȣ�Է�(01044446666)
email : �׳� �˾Ƽ� ����(���ڿ�ó��) ��������(40��)
����å���� : �� �� 10 ��
(ID , ������ )(ID�� ������Ͻ� �ο���ID)

ȸ��������
�ּ� , email, hp��ȣ�� ��������

ȸ�������� 5�ڷ�
�繰��( �������յ� Ű���� ��Ȯ�� �Է��� ���� )(Ʋ���� �繰��)3ȸ�� ����

*/
//< �޴� ���
void menuOutput(void)
{
	puts("1.ȸ������");
	puts("2.ȸ���˻�");
	puts("3.ȸ���������");
	puts("0.����");
	printf("�Է� : ");
}

void makeFile()
{
	//< �ε���;
	int maxIndex = 0;
	int curIndex = 0;

	//< ��� ����
	MemberInfo member = { 0 };
	//< ����������(�ε���)
	FILE* fp = NULL;

	//< ���� ����
	if ((fp = fileOpen("index.txt", "w+")) == NULL)
	{
		system("pause");
	}
	//< �뵵�� �°�(����)
	fwrite(&maxIndex, sizeof(int), 1, fp);
	fwrite(&curIndex, sizeof(int), 1, fp);
	//fprintf(indexFp, "%d", 0);
	//< ���� �ݱ�
	puts("index.txt �����Ϸ�");
	fclose(fp);

	//< ���� ����
	if ((fp = fileOpen("memberInfo.txt", "w+")) == NULL)
	{
		system("pause");
	}
	//< �뵵�� �°�(����)
	fwrite(&member, sizeof(MemberInfo), 1, fp);
	//fprintf(indexFp, "%d", 0);
	puts("memberInfo.txt �����Ϸ�");
	//< ���� �ݱ�
	fclose(fp);

	system("pause");
}


//< 40������
int limitInput(char* str, const int length)
{
	while (TRUE)
	{
		int num = 0;
		inputString(str);
		num = strlen(str);
		if (num >= length)
		{
			puts("�Է¿���:���������ʰ�");
		}
		else break;
	}

	return SUCCESS;
}

//�ε��� �ѹ� ����
int saveIndexNumber(void)
{
	int index = 0;
	FILE *fp;

	//���� ��Ʈ�� ����, ���� üũ
	if ((fp = _fsopen("index.txt", "r", _SH_DENYNO)) == NULL)
	{
		puts("index.txt ���� ����");
		return 0;
	}

	//�뵵�� �°� ��� �ϱ�
	//fscanf(fp, "%d",&index);
	fread(&index, sizeof(int), 1, fp);
	//���� �ݱ�
	fclose(fp);

	return index;
}

//< ȸ�� ���
void registrationMember(void)
{
	//< �Է�Ŀ�ǵ�
	int inputCommand;
	//< �ε���;
	int maxIndex = 0, curIndex = 0;
	//< ����ü
	MemberInfo member = { 0, };
	//< �ݺ���
	int i;
	//< ����������(�ε���)
	FILE* indexFp = NULL;
	//< ����������(ȸ������)
	FILE* fp = NULL;

	//< �ε��� �о����
	if ((indexFp = fileOpen("index.txt", "r")) == NULL)
	{
		return;
	}
	else
	{
		//< �뵵�� �°�(�б�)
		fread(&maxIndex, sizeof(int), 1, indexFp);
		fread(&curIndex, sizeof(int), 1, indexFp);
		//fscanf_s(indexFp, "%d", &index);
		//< ���� �ݱ�
		fclose(indexFp);
	}

	//< �Է�
	while (TRUE)
	{
		//< ȭ�������
		system("cls");
		//< ���
		puts("1.����");
		puts("0.�ڷΰ���");
		printf("�Է� : ");
		//< ����Է�
		inputCommand = inputNumber();
		//< �ڷΰ���
		switch (inputCommand)
		{
			//< ����
		case END: { system("pause"); return; }break;
			//< ����
		case REGESTRATION:
		{
			/*
			ID : ����ID����(???)(�ڵ������ϱ�) - ��������
			�̸� : �ߺ�����
			�ּ� : ���ڿ�����(40�ڱ����Է°���) �ѱ۱���
			�ֹι�ȣ : �ߺ�����(6�� üũ���� - 000405(6�ڸ�Ȯ��)
			hp��ȣ : -�� ������ ��ȣ�Է�(01044446666)
			email : �׳� �˾Ƽ� ����(���ڿ�ó��) ��������(40��)
			����å���� : �� �� 10 ��
			(ID , ������ )(ID�� ������Ͻ� �ο���ID)
			*/
			//< �����Է�

			printf("�̸� : ");
			limitInput(member.name, MAX_LENGTH);
			printf("�ּ� : ");
			limitInput(member.address, MAX_LENGTH);
			printf("�ֹι�ȣ : ");
			limitInput(member.signNumber, MAXSIGN);
			printf("�ڵ�����ȣ : ");
			limitInput(member.phoneNumber, MAX_LENGTH);
			printf("E-Mail : ");
			limitInput(member.email, MAX_LENGTH);

			for (i = 0; i < MAXBOOK; i++)
			{
				member.bookList[i] = 0;
			}
			maxIndex++;
			curIndex++;
			member.id = maxIndex;
		}
		break;
		}
		//< �ε��� ����
		//< ���� ����
		if ((indexFp = fileOpen("index.txt", "w")) == NULL)
		{
			return;
		}
		else
		{
			//< �뵵�� �°�(�б�)
			fwrite(&maxIndex, sizeof(int), 1, indexFp);
			fwrite(&curIndex, sizeof(int), 1, indexFp);
			//< ���� �ݱ�
			fclose(indexFp);
		}
		//< ȸ������ ����
		//< ���� ����
		if ((fp = fileOpen("memberInfo.txt", "a+")) == NULL)
		{
			return;
		}
		else
		{
			//< �뵵�� �°�(����)
			fwrite(&member, sizeof(MemberInfo), 1, fp);
			//< ���� �ݱ�
			fclose(indexFp);
		}
	}
}

//ȸ�� �˻�
void searchMember()
{
	int i = 0;
	int j = 0;
	int choiceUser = 0;
	int selectMode = 0;
	int index = saveIndexNumber();
	char inputsignNumber[80];
	MemberInfo save[100];

	//ȸ�� ���� �ҷ�����
	FILE *fp;
	//���� ����,���� üũ
	if ((fp = _fsopen("memberInfo.txt", "r", _SH_DENYNO)) == NULL)
	{
		puts("memberInfo.txt ���� ����");
		return;
	}
	
	//�뵵�� �°� ����
	fread(&save, sizeof(MemberInfo), index, fp);
	//���� �ݱ�
	fclose(fp);
	system("cls");
	while (TRUE)
	{
		printf("ã���� ȸ���� �ֹε�Ϲ�ȣ �� 6�ڸ��� �Է� �ϼ���\n");
		printf("���� �޴��� ���÷��� 0 �� �Է� �ϼ���\n");
		printf("�Է� : ");
		inputString(inputsignNumber);
		if (strncmp(inputsignNumber,"0",1) == 0)
		{
			return ;
		}

	/*	if (strlen(inputsignNumber) != 6)
		{
			printf("�ֹε�Ϲ�ȣ ���ڸ��� 6�ڸ� �Դϴ�.");
			Sleep(1000);
			system("cls");
		}*/
		system("cls");
		puts("------------------------------------------- ȸ������ ----------------------------------------------");
		puts("");
		printf("%4s%8s%20s%15s%15s%20s%15s\n",
			"ID", "�̸�", "�ּ�", "�ֹι�ȣ", "hp", "email", "����å����");
		puts("");
		puts("---------------------------------------------------------------------------------------------------");

		//�Է¹��� �ֹ� ��� ��ȣ�� ����� �ֹε�� ��ȣ�� ��ġ �ϸ� ȭ�鿡 ���
		for (i = 0; i < index; i++)
		{
			if (strcmp(inputsignNumber, save[i].signNumber) == 0)
			{
				//printf("ID : %d\n�̸� : %s\n�ּ� : %s\n�ֹι�ȣ : %s\nhp : %s\nemail : %s\n����å���� : %d\n",
				printf("%4d%8s%20s%15s%15s%20s%15d\n",
					save[i].id, save[i].name, save[i].address, save[i].signNumber, save[i].phoneNumber,
					save[i].email, save[i].bookList[0]);

				for (j = 1; j < MAXBOOK; j++)
				{
					printf("%4s%8s%20s%15s%15s%20s%15d\n",
						"", "", "", "", "", "", save[i].bookList[i]);
					//printf("%14d\n", member[i].bookList[j]);
				}
				puts("---------------------------------------------------------------------------------------------------");

			}
		}

		printf("���� �Ǵ� �����Ͻ� ȸ�� ��ȣ�� �Է� �ϼ���\n");
		choiceUser = inputNumber();

		system("cls");
		printf("���� �Ǵ� ������ ���� �ϼ���\n");
		printf("1. ����\n");
		printf("2. ����\n");
		printf("0. ���� �޴���\n");
		printf("���� : ");

		selectMode = inputNumber();

		system("cls");
		//�޴� ���ÿ� ���� ���
		switch (selectMode)
		{
		case 1: {fixMember(choiceUser, index); }break;
		case 2: {deleteMember(choiceUser, index); }break;
		case 0: {return; }
		default: {return; }break;
		}
	}
}

//ȸ������ ����
void fixMember(int num, int index)
{
	MemberInfo save[100];
	int selectNum;
	while (TRUE)
	{
		printf("�ٲ� �����͸� �Է� �ϼ���\n");
		printf("1. �ּ�\n");
		printf("2. email\n");
		printf("3. HP��ȣ\n");
		printf("0. ���� �޴���\n");
		printf("���� : ");
		selectNum = inputNumber();
		system("cls");
		switch (selectNum)
		{
		case 1:
		{
			//���� ������ ����
			FILE *fp;

			//���� ����,���� üũ
			if ((fp = _fsopen("memberInfo.txt", "r", _SH_DENYNO)) == NULL)
			{
				puts("memberInfo.txt ���� ����");
				return;
			}
			//�뵵�� �°� ����
			fread(&save, sizeof(MemberInfo), index, fp);

			//���� �ݱ�
			fclose(fp);

			printf("�ٲ� �ּ� �� �Է� �ϼ���.\n");
			inputString(save[num - 1].address);
			printf("�ּ� ������ �Ϸ� �Ǿ����ϴ�.");

			Sleep(1000);
			system("cls");

			//���� ����,���� üũ
			if ((fp = _fsopen("memberInfo.txt", "w", _SH_DENYNO)) == NULL)
			{
				puts("memberInfo.txt ���� ����");
				return;
			}
			//�뵵�� �°� ����
			fwrite(&save, sizeof(MemberInfo), index, fp);
			//���� �ݱ�
			fclose(fp);
		}
		break;

		case 2:
		{
			//���� ������ ����
			FILE *fp;

			//���� ����,���� üũ
			if ((fp = _fsopen("memberInfo.txt", "r", _SH_DENYNO)) == NULL)
			{
				puts("memberInfo.txt ���� ����");
				return;
			}
			//�뵵�� �°� ����
			fread(&save, sizeof(MemberInfo), index, fp);
			//���� �ݱ�
			fclose(fp);

			printf("�ٲ� email �ּҸ� �Է� �ϼ���.\n");
			inputString(save[num - 1].email);
			printf("email ������ �Ϸ� �Ǿ����ϴ�.\n");
			Sleep(1000);
			system("cls");

			//ȸ������ ����
			//���� ����,���� üũ
			if ((fp = _fsopen("memberInfo.txt", "w", _SH_DENYNO)) == NULL)
			{
				puts("memberInfo.txt ���� ����");
				return;
			}
			//�뵵�� �°� ����
			fwrite(&save, sizeof(MemberInfo), index, fp);
			//���� �ݱ�
			fclose(fp);
		}
		break;

		case 3:
		{
			//���� ������ ����
			FILE *fp;

			//���� ����,���� üũ
			if ((fp = _fsopen("memberInfo.txt", "r", _SH_DENYNO)) == NULL)
			{
				puts("memberInfo.txt ���� ����");
				return;
			}
			//�뵵�� �°� ����
			fread(&save, sizeof(MemberInfo), index, fp);
			//���� �ݱ�
			fclose(fp);

			printf("�ٲ� HP��ȣ�� �Է� �ϼ���.\n");
			inputString(save[num - 1].phoneNumber);
			printf("HP��ȣ ������ �Ϸ� �Ǿ����ϴ�.\n");

			Sleep(1000);
			system("cls");

			//ȸ������ ����
			//���� ����,���� üũ
			if ((fp = _fsopen("memberInfo.txt", "w", _SH_DENYNO)) == NULL)
			{
				puts("memberInfo.txt ���� ����");
				return;
			}
			//�뵵�� �°� ����
			fwrite(&save, sizeof(MemberInfo), index, fp);
			//���� �ݱ�
			fclose(fp);
		}
		break;

		case 0:
		{
			system("cls");
			return;
		}
		default:
			break;
		}
	}
}

//ȸ�� ����
void deleteMember(int num, int index)
{
	MemberInfo save[100];
	int i, j;
	char inputDeletetext[80];
	char deleteText[5];

	//���� ������ ����
	FILE *fp;

	//���� ����,���� üũ
	if ((fp = _fsopen("memberInfo.txt", "r", _SH_DENYNO)) == NULL)
	{
		puts("memberInfo.txt ���� ����");
		return;
	}
	//�뵵�� �°� ����
	fread(&save, sizeof(MemberInfo), index, fp);
	//���� �ݱ�
	fclose(fp);

	printf("���� ���� �Ͻ÷��� �Ʒ��� ������ ��Ȯ�� �Է� �ϼ���\n");
	srand((unsigned int)time(0));
	for (j = 0; j < 5; j++)
	{
		deleteText[j] = (rand() % 26) + 65;
	}
	for (j = 0; j < 5; j++)
	{
		printf("%c", deleteText[j]);
	}
	puts("");
	printf("�Է� : ");

	inputString(inputDeletetext);

	for (i = 0; i < 2; i++)
	{
		if ((strlen(inputDeletetext) != 5))
		{
			system("cls");
			printf("5���� ���ڸ� �Է� �ϼ���\n");

			srand((unsigned int)time(0));
			for (j = 0; j < 5; j++)
			{
				deleteText[j] = (rand() % 26) + 65;
			}
			for (j = 0; j < 5; j++)
			{
				printf("%c", deleteText[j]);
			}
			puts("");

			printf("�Է� : ");
			inputString(inputDeletetext);
		}

		else if (strlen(inputDeletetext) == 5 && (strncmp(inputDeletetext, deleteText, 5) != 0))
		{
			system("cls");
			printf("�Է��Ͻ� ���ڰ� ��Ȯ���� �ʽ��ϴ� �ٽ� �Է��� �ּ���\n");

			srand((unsigned int)time(0));
			for (j = 0; j < 5; j++)
			{
				deleteText[j] = (rand() % 26) + 65;
			}
			for (j = 0; j < 5; j++)
			{
				printf("%c", deleteText[j]);
			}
			puts("");

			printf("�Է� : ");
			inputString(inputDeletetext);

		}
		else if ((strlen(inputDeletetext) == 5) && (strncmp(inputDeletetext, deleteText, 5) == 0))
		{
			if (save[num - 1].bookList[0] != 0)
			{
				printf("���� å�� �ִ� ȸ�� ������ ���� �ϽǼ� �����ϴ�.");
				return;
			}
			else
			{
				save[num - 1].id = 0;
				strcpy_s(save[num - 1].name, MAX_LENGTH, "delete");
				strcpy_s(save[num - 1].email, MAX_LENGTH, "delete");
				strcpy_s(save[num - 1].address, MAX_LENGTH, "delete");
				strcpy_s(save[num - 1].signNumber, MAX_LENGTH, "delete");
				strcpy_s(save[num - 1].phoneNumber, MAX_LENGTH, "delete");
				for (i = 0; i < 10; i++)
				{
					save[i].bookList[0] = 0;
				}				
				printf("%d�� ȸ���� ���� ������ �Ϸ� �Ǿ����ϴ�.", num);
				Sleep(1000);
				system("cls");
			}
		}
	}
	//ȸ������ ����
	//���� ����,���� üũ
	if ((fp = _fsopen("memberInfo.txt", "w", _SH_DENYNO)) == NULL)
	{
		puts("memberInfo.txt ���� ����");
		return;
	}
	//�뵵�� �°� ����
	fwrite(&save, sizeof(MemberInfo), index, fp);
	//���� �ݱ�
	fclose(fp);
}


//< ȸ�� ���
void memberOutput(void)
{
	//< ����ü
	LPMemberInfo member = NULL;
	//< �ε���;
	int maxIndex = 0, curIndex = 0;
	//< ����������(�ε���)
	FILE* indexFp = NULL;
	//< ����������(ȸ������)
	FILE* fp = NULL;
	//< �ݺ���
	int i, j;
	//< ���� ũ��
	int fileSize = 0;

	//< ȭ�������
	system("cls");
	puts("------------------------------------------- ȸ������ ----------------------------------------------");
	puts("");
	printf("%4s%8s%20s%15s%15s%20s%15s\n",
		"ID", "�̸�", "�ּ�", "�ֹι�ȣ", "hp", "email", "����å����");
	puts("");
	puts("---------------------------------------------------------------------------------------------------");
	//< ���� üũ
	if ((indexFp = fileOpen("index.txt", "r")) == NULL)
	{
		return;
	}
	else
	{
		//< �뵵�� �°�(�б�)
		fread(&maxIndex, sizeof(int), 1, indexFp);
		fread(&curIndex, sizeof(int), 1, indexFp);
		//fscanf_s(indexFp, "%d", &index);
		//< ���� �ݱ�
		fclose(indexFp);
	}

	//< ���� �б�
	if ((fp = fileOpen("memberInfo.txt", "r")) == NULL)
	{
		return;
	}
	else
	{
		//< �����Ҵ�
		if (member == NULL)
		{
			member = (LPMemberInfo)malloc(sizeof(MemberInfo)*curIndex);
		}
		//< �뵵�� �°�(�б�)
		fread(member, sizeof(MemberInfo), maxIndex, fp);

		//< ���� �ݱ�
		fclose(fp);
	}
	for (i = 0; i < maxIndex; i++)
	{
		//printf("ID : %d\n�̸� : %s\n�ּ� : %s\n�ֹι�ȣ : %s\nhp : %s\nemail : %s\n����å���� : %d\n",
		printf("%4d%8s%20s%15s%15s%20s%15d\n",
			member[i].id, member[i].name, member[i].address, member[i].signNumber, member[i].phoneNumber,
			member[i].email, member[i].bookList[0]);

		for (j = 1; j < MAXBOOK; j++)
		{
			printf("%4s%8s%20s%15s%15s%20s%15d\n",
				"", "", "", "", "", "", member[i].bookList[i]);
			//printf("%14d\n", member[i].bookList[j]);
		}
		puts("---------------------------------------------------------------------------------------------------");
	}
	free(member);
	system("pause");
}