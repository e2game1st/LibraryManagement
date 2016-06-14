#include "LibraryManagement.h"

int main(int argc, char *argv[])
{
	int inputCommand = 0;
	
	puts("1.회원관리");
	puts("2.도서관리");
	puts("3.대출관리");
	puts("0.종료");
	printf("입력 : ");

	inputCommand = inputNumber();

	switch (inputCommand)
	{
		case MEMBER_M:
			{ 
				//< 파일 여부 체크
				checkFile();
				//< 회원 관리
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
