#include "LibraryManagement.h"


/*
1. 회원정보관리

a. 회원가입
b. 회원검색(주민번호검색 앞 6자리만관리) (겹칠시 모두출력)
ㄱ.회원수정
ㄴ.회원삭제
c. 회원정보출력(모든회원보기)

- 회원정보
: id, 이름, 주소, 주민번호(6자리),hp번호,Email,빌린책

0000000000 자리로 관리(10자리)
ID : 고유ID관리(???)(자동관리하기) - 순차관리
이름 : 중복가능
주소 : 문자열관리(40자까지입력가능) 한글기준
주민번호 : 중복가능(6자 체크가입 - 000405(6자리확인)
hp번호 : -를 제외한 번호입력(01044446666)
email : 그냥 알아서 가입(문자열처리) 길이제한(40자)
빌린책정보 : 총 몇 10 권
(ID , 도서명 )(ID는 도서등록시 부여된ID)

회원수정시
주소 , email, hp번호만 수정가능

회원삭제시 5자로
재물음( 임의조합된 키값을 정확히 입력후 삭제 )(틀릴시 재물음)3회후 종료

*/
//< 메뉴 출력
void menuOutput(void)
{
	puts("1.회원가입");
	puts("2.회원검색");
	puts("3.회원정보출력");
	puts("0.종료");
	printf("입력 : ");
}

void makeFile()
{
	//< 인덱스;
	int maxIndex = 0;
	int curIndex = 0;

	//< 멤버 정보
	MemberInfo member = { 0 };
	//< 파일포인터(인덱스)
	FILE* fp = NULL;

	//< 파일 오픈
	if ((fp = fileOpen("index.txt", "w+")) == NULL)
	{
		system("pause");
	}
	//< 용도에 맞게(쓰기)
	fwrite(&maxIndex, sizeof(int), 1, fp);
	fwrite(&curIndex, sizeof(int), 1, fp);
	//fprintf(indexFp, "%d", 0);
	//< 파일 닫기
	puts("index.txt 생성완료");
	fclose(fp);
	
	//< 파일 오픈
	if ((fp = fileOpen("memberInfo.txt", "w+")) == NULL)
	{
		system("pause");
	}
	//< 용도에 맞게(쓰기)
	fwrite(&member, sizeof(MemberInfo), 1, fp);
	//fprintf(indexFp, "%d", 0);
	puts("memberInfo.txt 생성완료");
	//< 파일 닫기
	fclose(fp);

	system("pause");
}

//< 40자제한
int limitInput(const char* str, const int length)
{
	while (TRUE)
	{
		inputString(str);
		if(strlen(str) >= length)
		{
			puts("입력오류:글자제한초과");
		}
		else break;
	}

	return SUCCESS;
}

//< 회원 등록
void registrationMember(void)
{
	//< 입력커맨드
	int inputCommand;
	//< 인덱스;
	int maxIndex = 0, curIndex = 0;
	//< 구조체
	MemberInfo member = { 0, };
	//< 반복용
	int i;
	//< 파일포인터(인덱스)
	FILE* indexFp = NULL;
	//< 파일포인터(회원정보)
	FILE* fp = NULL;

	//< 인덱스 읽어오기
	if ((indexFp = fileOpen("index.txt", "r")) == NULL)
	{
		return;
	}
	else
	{
		//< 용도에 맞게(읽기)
		fread(&maxIndex, sizeof(int), 1, indexFp);
		fread(&curIndex, sizeof(int), 1, indexFp);
		//fscanf_s(indexFp, "%d", &index);
		//< 파일 닫기
		fclose(indexFp);
	}

	//< 입력
	while (TRUE)
	{
		//< 화면지우기
		system("cls");
		//< 출력
		puts("1.가입");
		puts("0.뒤로가기");
		printf("입력 : ");
		//< 명령입력
		inputCommand = inputNumber();
		//< 뒤로가기
		switch (inputCommand)
		{
			//< 종료
			case END: { system("pause"); return; }break;
			//< 가입
			case REGESTRATION:
			{
				/*
				ID : 고유ID관리(???)(자동관리하기) - 순차관리
				이름 : 중복가능
				주소 : 문자열관리(40자까지입력가능) 한글기준
				주민번호 : 중복가능(6자 체크가입 - 000405(6자리확인)
				hp번호 : -를 제외한 번호입력(01044446666)
				email : 그냥 알아서 가입(문자열처리) 길이제한(40자)
				빌린책정보 : 총 몇 10 권
				(ID , 도서명 )(ID는 도서등록시 부여된ID)
				*/
				//< 정보입력
				while (TRUE)
				{
					printf("이름 : ");
					limitInput(member.name, MAX_LENGTH);
					
					printf("주소 : ");
					limitInput(member.address, MAX_LENGTH); 
					printf("주민번호 : ");
					limitInput(member.signNumber, MAXSIGN);
					printf("핸드폰번호 : ");
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
					puts("길이제한초과 이전 화면으로 돌아갑니다.");
					return;
				}
				if (limitInput(member.signNumber, MAXSIGN) == FAIL)
				{
					puts("주민등록번호 6자리가 맞지 않습니다");
					puts("이전 화면으로 돌아갑니다.");
					return;
				}
				*/
				
			}
			break;
		}
		//< 인덱스 저장
		//< 파일 오픈
		if ((indexFp = fileOpen("index.txt", "w")) == NULL)
		{
			return;
		}
		else
		{
			//< 용도에 맞게(읽기)
			fwrite(&maxIndex, sizeof(int), 1, indexFp);
			fwrite(&curIndex, sizeof(int), 1, indexFp);
			//< 파일 닫기
			fclose(indexFp);
		}
		//< 회원정보 저장
		//< 파일 오픈
		if ((fp = fileOpen("memberInfo.txt", "a+")) == NULL)
		{
			return;
		}
		else
		{
			//< 용도에 맞게(쓰기)
			fwrite(&member, sizeof(MemberInfo), 1, fp);
			//< 파일 닫기
			fclose(indexFp);
		}
	}
}

//< 회원 출력
void memberOutput(void)
{
	//< 구조체
	LPMemberInfo member = NULL;
	//< 인덱스;
	int maxIndex = 0, curIndex = 0;
	//< 파일포인터(인덱스)
	FILE* indexFp = NULL;
	//< 파일포인터(회원정보)
	FILE* fp = NULL;
	//< 반복용
	int i, j;
	//< 파일 크기
	int fileSize = 0;

	//< 화면지우기
	system("cls");
	puts("------------------------------------------- 회원정보 ----------------------------------------------");
	puts("");
	printf("%4s%8s%20s%15s%15s%20s%15s\n",
		"ID", "이름", "주소", "주민번호", "hp", "email", "빌린책정보");
	puts("");
	puts("---------------------------------------------------------------------------------------------------");
	//< 파일 체크
	if ((indexFp = fileOpen("index.txt", "r")) == NULL)
	{
		return;
	}
	else
	{
		//< 용도에 맞게(읽기)
		fread(&maxIndex, sizeof(int), 1, indexFp);
		fread(&curIndex, sizeof(int), 1, indexFp);
		//fscanf_s(indexFp, "%d", &index);
		//< 파일 닫기
		fclose(indexFp);
	}

	//< 파일 읽기
	if ((fp = fileOpen("memberInfo.txt", "r")) == NULL)
	{
		return;
	}
	else
	{
		//< 동적할당
		if (member == NULL)
		{
			member = (LPMemberInfo)malloc(sizeof(MemberInfo)*curIndex);
		}
		//< 용도에 맞게(읽기)
		fread(member, sizeof(MemberInfo), maxIndex, fp);

		//< 파일 닫기
		fclose(fp);
	}
	for (i = 0; i < maxIndex; i++)
	{
		//printf("ID : %d\n이름 : %s\n주소 : %s\n주민번호 : %s\nhp : %s\nemail : %s\n빌린책정보 : %d\n",
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