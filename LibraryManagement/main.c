#include "LibraryManagement.h"

int main(int argc, char *argv[])
{
	int inputCommand = 0;
	
	puts("1.ȸ������");
	puts("2.��������");
	puts("3.�������");
	puts("0.����");
	printf("�Է� : ");

	inputCommand = inputNumber();

	switch (inputCommand)
	{
		case MEMBER_M:
			{ 
				//< ���� ���� üũ
				checkFile();
				//< ȸ�� ����
				registrator(); 
			}
			break;
		case BOOK_M:
			{
				return;
			}
			break;
		case BILLING_M:
			{
				return;
			}
			break;
		case END:
		default:
			{
				return;
			}
			break;
	}


	return 0;
}
