#include "member.h"

//< 파일 생성
void checkFile(void)
{
	FILE *fp = NULL, *fp2 = NULL;

	//< 파일 생성
	if (((fp = fileOpen("index.txt", "r")) == NULL)
		|| ((fp2 = fileOpen("index.txt", "r")) == NULL))
	{
		//< 파일여부 체크
		makeFile();
	}
	else
	{
		fclose(fp);
		fclose(fp2);
	}
}

//< 회원
void registrator(void)
{
	//< 입력커맨드
	int inputCommand;
	while (TRUE)
	{
		//< 화면지우기
		system("cls");
		//< 메뉴출력
		menuOutput();
		//< 입력
		inputCommand = inputNumber();
		//< 분기처리
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