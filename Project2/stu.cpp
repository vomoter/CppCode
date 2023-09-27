#include"people.h"

void Menu() 
{
	cout << "====== �ṹ������ͨѶ¼����ϵͳ ======" << endl;
	cout << "\t1.�����ϵ��" << endl;
	cout << "\t2.��ʾ��ϵ��" << endl;
	cout << "\t3.ɾ����ϵ��" << endl;
	cout << "\t4.������ϵ��" << endl;
	cout << "\t5.�޸���ϵ��" << endl;
	cout << "\t6.�����ϵ��" << endl;
	cout << "\t0.�˳�ͨѶ¼" << endl;
	cout << "������ѡ��";
}

//�����ϵ��
void AddPeople(C* c)
{
	if (c->len == MAXSIZE)
	{
		return;
	}
	else 
	{
		string name;
		int sex;
		int age;
		string number;
		string address;
		cout << "������������" << endl;
		cin>>name;
		c->p[c->len].name = name;

		while (true)
		{
			cout << "�������Ա�(��Ϊ1��ŮΪ0)��" << endl;
			cin >> sex;
			if (sex == 1 || sex == 0) {
				c->p[c->len].sex = sex;
				break;
			}
		}
		
		while (true)
		{
			cout << "���������䣺" << endl;
			cin >> age;
			if (age >=0 && age<=120) {
				c->p[c->len].age = age;
				break;
			}
			
		}

		while (true)
		{
			cout << "�������ֻ����룺" << endl;
			cin >> number;
			if (number.length() == 11) {
				c->p[c->len].number = number;
				break;
			}
		}

		cout << "�������ַ��" << endl;
		cin >>address;
		c->p[c->len].address = address;
		
	}
	c->len += 1;


}

//��ӡͨѶ¼
void DispalyPeople(C* c) 
{

	for (int i = 0; i < c->len; i++)
	{
		int temp=c->p[i].sex;
		string sex;
		if (temp == 1) sex = "��";
		else sex = "Ů";
		cout <<c->p[i].name<<"\t" << sex <<"\t" 
			<<c->p[i].age <<"\t" << c->p[i].number << "\t" << c->p[i].address << endl;
	}
}

//��ϵ����������
int IndexOfName(C* c,string name) {

	for (int i = 0; i < c->len; i++)
	{
		if (c->p[i].name == name) 
		{
			return i;
			break;
		}
	}
	return -1;

}

//ɾ����ϵ��
void DeletePeople(C* c) {
	string name;
	cout << "������Ҫɾ��ͨѶ¼�˵�����:" << endl;
	cin >> name;
	if (IndexOfName(c, name) == -1)
	{
		cout << "û�в�ѯ����Ϣ��" << endl;
	}
	else 
	{
		int index = IndexOfName(c, name);
		for (int i = index; i < c->len; i++)
		{
			c->p[i] = c->p[i + 1];
			c->len -= 1;
		}
	}
}

//������ϵ��
void FindPeople(C* c)
{
	string name;
	cout << "������Ҫ��ѯ������:" << endl;
	cin>>name;

	if (IndexOfName(c, name) == -1) 
	{
		cout << "û�в�ѯ����Ϣ��" << endl;
	}
	else
	{
		int i = IndexOfName(c, name);
		int temp = c->p[i].sex;
		string sex;
		if (temp == 1) sex = "��";
		else sex = "Ů";
		cout << "����:" << c->p[i].name << "  �Ա�:" << sex << "  ����:"
			<< c->p[i].age << "  �ֻ�����:" << c->p[i].number << "  ��ַ:" << c->p[i].address << endl;
	}
}

//�޸���ϵ��
void AlterPeople(C* c) {
	string name;
	cout << "������Ҫ�޸�ͨѶ¼�˵�����:" << endl;
	cin >> name;
	if (IndexOfName(c, name) == -1)
	{
		cout << "û�в�ѯ����Ϣ��" << endl;
	}
	else
	{
		int n = IndexOfName(c, name);
		string newname;
		int sex;
		int age;
		string number;
		string address;
		cout << "������������" << endl;
		cin >> newname;
		c->p[n].name = newname;

		while (true)
		{
			cout << "�������Ա�(��Ϊ1��ŮΪ0)��" << endl;
			cin >> sex;
			if (sex == 1 || sex == 0) {
				c->p[n].sex = sex;
				break;
			}
		}

		while (true)
		{
			cout << "���������䣺" << endl;
			cin >> age;
			if (age >= 0 && age <= 120) {
				c->p[n].age = age;
				break;
			}

		}

		while (true)
		{
			cout << "�������ֻ����룺" << endl;
			cin >> number;
			if (number.length() == 11) {
				c->p[n].number = number;
				break;
			}
		}

		cout << "�������ַ��" << endl;
		cin >> address;
		c->p[n].address = address;

	}
	
}

//���ͨѶ¼
void ClearInfo(C* c) {

	c->len = 0;
	cout << "ͨѶ¼�Ѿ����!" << endl;
}

int main() {
	struct Contact C;
	C.len = 0;
	Menu();
	bool b = true;
	int choice;
	while (b)
	{
		cin >> choice;
		switch (choice)
		{
		case addPeople:AddPeople(&C); break;
		case dispalyPeople:cout << "����" << "\t�Ա�"  << " \t����"<< "\t�ֻ�����"<< "\t��ַ" << endl;
			DispalyPeople(&C); break;
		case deletePeople:DeletePeople(&C); break;
		case findPeople:FindPeople(&C);break;
		case alterPeople:AlterPeople(&C); break;
		case clearInfo:ClearInfo(&C); break;
		case EXIT:b = false;
			cout << "�˳�" << endl;
			exit(0);
			break;

		default:cout << "���벻����" << endl;
			break;
		}
		system("pause");
		system("cls");
		Menu();
	}
	return 0;
}