#ifndef __MEMBERMANAGEMENT_H__
#define __MEMBERMANAGEMENT_H__

#include "LibraryManagement.h"

//< 파일 생성
void makeFile();

//< 40자제한
int limitInput(char* str, const int length);

//인덱스 넘버 저장
int saveIndexNumber(void);

//< 메뉴 출력
void menuOutput(void);

//< 회원 등록
void registrationMember(void);

//회원 검색
void searchMember();

//회원정보 수정
void fixMember(int num, int index);

//회원 삭제
void deleteMember(int num, int index);

//< 회원 전체 출력
void memberOutput(void);

#endif // !__LIBRARYMANAGEMENT_H__