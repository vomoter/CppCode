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

void Menu();//���˵�
void AddPeople(C *c);//�����ϵ��
void DispalyPeople(C *c);//��ӡͨѶ¼
int IndexOfName(C* c,string name);//��ϵ����������
void DeletePeople(C *c);//ɾ����ϵ��
void FindPeople(C *c);//������ϵ��
void AlterPeople(C *c);//�޸���ϵ����Ϣ
void ClearInfo(C* c);//���ͨѶ¼


