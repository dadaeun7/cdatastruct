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
	printf("\n�̸�: ");
	scanf_s("%s", inName, nameSize);
	printf("����: ");
	scanf_s("%d", inAge);
	printf("�޴��� ��ȣ: ");
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
		printf("���� ����Ʈ�� ����,����,�߰� �غ�����!\n");
		printf("search[s], add[a], exit[q], preview[p], remove[r]");
		scanf_s("%c", &iNumber, sizeof(iNumber));

		if (iNumber == 'q') {
			printf("�˻��� �����մϴ�.\n");
			printf("------ UserList �� ��� �����մϴ�. ------\n");
			userListFree();
			return;
		}

		switch (iNumber) 
		{
			case 'p' :
				printf("------ ���� UserList --------\n");
				showUserList();
				printf("\n");
				getchar();
				break;
			case 'r':
				printf("------ ���� ������ �̸��� �Է����ּ���. --------\n");
				inputName(inName, sizeof(inName));
				removeUser(searchUser(inName));
				getchar();
				break;
			case 's' :
				printf("------ �˻� �� �̸��� �Է����ּ���. ------\n");
				inputName(inName, sizeof(inName));
				searchUser(inName);
				getchar();
				break;
			case 'a' :
				printf("------- �߰��� ������ ������ �Է����ּ���.-------");
				char addName[30];
				char addPhone[30];
				int addAge = 0;
				inputUserData(&addAge, addName, sizeof(addName), addPhone, sizeof(addPhone));
				addUserList(addAge, addName, addPhone);
				printf("���� ������ ���������� �߰� �Ϸ�Ǿ����ϴ�.\n\n");
				getchar();
				break;
			default:
				printf("�ٽ� �Է����ּ���\n\n");
				break;
		}
	}
	return 0;
}