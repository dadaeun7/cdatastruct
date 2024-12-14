#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singlyLinkedList.h"

void inputName(char* outputName, int size)
{
	scanf_s("%s", outputName, size);  
}

void inputUserData(int* inAge, char* inName, int nameSize, char* inPhone, int phoneSize)
{
	printf("\n이름: ");
	scanf_s("%s", inName, nameSize);
	printf("나이: ");
	scanf_s("%d", inAge);
	printf("휴대폰 번호: ");
	scanf_s("%s", inPhone, phoneSize);
}

int main(void)
{

	int age[3] = { 32, 27, 18 };
	char* name[3] = { "parkdaeun", "hanmini", "moonsagsun" };
	char* phone[3] = { "01043241154", "01022445454", "01088724324" };

	for (int i = 0; i < 3; i++) {
		addUserList(age[i], name[i], phone[i]);
	}

	while (1) {

		char iNumber;
		char inName[30] = "";
		printf("유저 리스트를 수정,삭제,추가 해보세요!\n");
		printf("search[s], add[a], exit[q], preview[p], remove[r]");
		scanf_s("%c", &iNumber, sizeof(iNumber));

		if (iNumber == 'q') {
			printf("검색을 종료합니다.\n");
			printf("------ UserList 를 모두 해제합니다. ------\n");
			userListFree();
			return;
		}

		switch (iNumber) 
		{
			case 'p' :
				printf("------ 현재 UserList --------\n");
				showUserList();
				printf("\n");
				getchar();
				break;
			case 'r':
				printf("------ 지울 유저의 이름을 입력해주세요. --------\n");
				inputName(inName, sizeof(inName));
				removeUser(searchUser(inName));
				getchar();
				break;
			case 's' :
				printf("------ 검색 할 이름을 입력해주세요. ------\n");
				inputName(inName, sizeof(inName));
				searchUser(inName);
				getchar();
				break;
			case 'a' :
				printf("------- 추가할 유저의 정보를 입력해주세요.-------");
				char addName[30];
				char addPhone[30];
				int addAge = 0;
				inputUserData(&addAge, addName, sizeof(addName), addPhone, sizeof(addPhone));
				addUserList(addAge, addName, addPhone);
				printf("유저 정보가 정상적으로 추가 완료되었습니다.\n\n");
				getchar();
				break;
			default:
				printf("다시 입력해주세요\n\n");
				break;
		}
	}
	return 0;
}