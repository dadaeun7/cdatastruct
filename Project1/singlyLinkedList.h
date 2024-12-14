#pragma once
typedef struct USERDATA USERDATA;

void addUserList(int uAge, const char* uName, const char* uPhone);
void showUserList();
void userListFree();
USERDATA* searchUser(const char* inputName);
void removeUser(USERDATA* preNode);