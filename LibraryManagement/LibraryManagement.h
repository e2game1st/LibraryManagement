#ifndef __LIBRARYMANAGEMENT_H__
#define __LIBRARYMANAGEMENT_H__

//< ����ϴ� �������
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

//< �ɺ��� ���
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
ID : ����ID����(???)(�ڵ������ϱ�) - ��������
�̸� : �ߺ�����
�ּ� : ���ڿ�����(40�ڱ����Է°���) �ѱ۱���
�ֹι�ȣ : �ߺ�����(6�� üũ���� - 000405(6�ڸ�Ȯ��)
hp��ȣ : -�� ������ ��ȣ�Է�(01044446666)
email : �׳� �˾Ƽ� ����(���ڿ�ó��) ��������(40��)
����å���� : �� �� 10 ��
(ID , ������ )(ID�� ������Ͻ� �ο���ID)
*/
//< ȸ������ ����ü
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