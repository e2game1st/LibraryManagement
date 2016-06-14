#ifndef __LIBRARYMANAGEMENT_H__
#define __LIBRARYMANAGEMENT_H__

//< 사용하는 헤더파일
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <share.h>
#include <Windows.h>
#include <time.h>
#include "input.h"
#include "fileIO.h"
#include "MemberManagement.h"
#include "member.h"

//< 심볼릭 상수
#define MAX_LENGTH 80
#define TRUE 1
#define FALSE 0
#define MAXBOOK 10
#define SUCCESS	TRUE
#define FAIL	FALSE
#define MAXSIGN 6

enum inputLibrary
{
	_END = 0,
	MEMBER_M,
	BOOK_M,
	BILLING_M
};

enum inputMember
{
	END=0,
	REGESTRATION,
	SEARCHMEMBER,
	OUTPUTMEMBER,
};


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
//< 회원정보 구조체
typedef struct tagLibraryMemberInfo
{
	unsigned int id;
	char name[MAX_LENGTH];
	char address[MAX_LENGTH];
	char signNumber[MAX_LENGTH];
	char phoneNumber[MAX_LENGTH];
	char email[MAX_LENGTH];
	int bookList[MAXBOOK];
}MemberInfo, *LPMemberInfo;

#endif // !__INPUT_H__