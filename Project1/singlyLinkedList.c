#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singlyLinkedList.h"

typedef struct USERDATA 
{
	int age;
	char name[30];
	char phone[15];
	USERDATA* uNext;  
	
}USERDATA;

USERDATA* g_headNode = NULL;

void addUserList(int uAge, const char* uName, const char* uPhone)
{
	USERDATA* newUser = (USERDATA*)malloc(sizeof(USERDATA));
	newUser->age = uAge;
	strcpy_s(newUser->name, sizeof(newUser->name), uName);
	strcpy_s(newUser->phone, sizeof(newUser->phone), uPhone);
	newUser->uNext = NULL;

	if (g_headNode == NULL) {
		g_headNode = newUser;
		return;
	}

	USERDATA* pUser = g_headNode;

	while (pUser->uNext != NULL) {
		pUser = pUser->uNext;
	}

	pUser->uNext = newUser;
	return;
}

void showUserList() 
{
	USERDATA* nextUser = g_headNode;

	if (g_headNode == NULL) {
		printf("Userlist is not exist\n");
		return 0;
	}

	while (1) {

		if (nextUser == NULL) {
			return;
		}

		printf("Age: %d / Name: %s / Phone: %s\n", nextUser->age, nextUser->name, nextUser->phone);
		nextUser = nextUser->uNext;
	}
}

void userListFree() 
{
	USERDATA* tempUser = g_headNode;
	USERDATA* freeUser = NULL;
	if (tempUser == NULL)
		return;

	while (tempUser != NULL) {
		printf("free User Data: age : [%d] name : [%s] phone : [%s]\n", tempUser->age, tempUser->name, tempUser->phone);
		freeUser = tempUser;
		tempUser = tempUser->uNext;
		free(freeUser);
	}

}

USERDATA* searchUser(char* inputName) 
{
	USERDATA* preUser = NULL;
	USERDATA* findUser = g_headNode;
	
	while (findUser != NULL) 
	{
		if (strcmp(findUser->name, inputName) == 0) {
			printf("exist!\n\n");
			return preUser;
		}
		preUser = findUser;
		findUser = findUser->uNext;
	}
	printf("Not exist .. \n\n");
	return NULL;
}

void removeUser(USERDATA* preNode) 
{

	if (preNode == NULL) {
		printf("존재하지 않은 유저는 삭제가 불가합니다.\n\n");
		return;
	}

	USERDATA* removeNode = preNode->uNext;
	USERDATA* inPreNode = preNode;
	USERDATA* nextNode = removeNode->uNext; // == preNode->uNext->uNext

	inPreNode->uNext = nextNode;
	printf("삭제 된 유저의 정보입니다. 이름: %s, 나이: %d, 휴대폰번호: %s\n",
		removeNode->name, removeNode->age, removeNode->phone);
	free(removeNode);
	printf("현재 유저 정보입니다. \n");
	showUserList();
}