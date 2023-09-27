#include<iostream>
#include<string>
const int MAXSIZE = 100;
using namespace std;
typedef struct People {
	string name;
	int sex;
	int age;
	string number;
	string address;
}P;

typedef struct Contact {
	P p[MAXSIZE];
	int len;
}C;

enum en {EXIT,addPeople,dispalyPeople,deletePeople,findPeople,alterPeople,clearInfo};

void Menu();//主菜单
void AddPeople(C *c);//添加联系人
void DispalyPeople(C *c);//打印通讯录
int IndexOfName(C* c,string name);//联系人姓名索引
void DeletePeople(C *c);//删除联系人
void FindPeople(C *c);//查找联系人
void AlterPeople(C *c);//修改联系人信息
void ClearInfo(C* c);//清空通讯录


