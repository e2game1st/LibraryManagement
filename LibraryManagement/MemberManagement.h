#ifndef __MEMBERMANAGEMENT_H__
#define __MEMBERMANAGEMENT_H__

#include "LibraryManagement.h"

//< ���� ����
void makeFile();

//< 40������
int limitInput(char* str, const int length);

//�ε��� �ѹ� ����
int saveIndexNumber(void);

//< �޴� ���
void menuOutput(void);

//< ȸ�� ���
void registrationMember(void);

//ȸ�� �˻�
void searchMember();

//ȸ������ ����
void fixMember(int num, int index);

//ȸ�� ����
void deleteMember(int num, int index);

//< ȸ�� ��ü ���
void memberOutput(void);

#endif // !__LIBRARYMANAGEMENT_H__