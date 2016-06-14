#include "LibraryManagement.h"


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
int limitInput(const char* str, const int length)
{
	while (TRUE)
	{
		inputString(str);
		if(strlen(str) >= length)
		{
			puts("�Է¿���:���������ʰ�");
		}
		else break;
	}

	return SUCCESS;
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
				while (TRUE)
				{
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
				}
				for (i = 0; i < MAXBOOK; i++)
				{
					member.bookList[i] = 0;
				}
				maxIndex++;
				curIndex++;
				member.id = maxIndex;

				/*
				if ((limitInput(member.address, MAX_LENGTH) == FAIL)
					|| (limitInput(member.phoneNumber, MAX_LENGTH) == FAIL)
					|| (limitInput(member.email, MAX_LENGTH) == FAIL)
					)
				{
					puts("���������ʰ� ���� ȭ������ ���ư��ϴ�.");
					return;
				}
				if (limitInput(member.signNumber, MAXSIGN) == FAIL)
				{
					puts("�ֹε�Ϲ�ȣ 6�ڸ��� ���� �ʽ��ϴ�");
					puts("���� ȭ������ ���ư��ϴ�.");
					return;
				}
				*/
				
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