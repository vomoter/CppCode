#include<iostream>
#include<string>
using namespace std;

//�ֻ���
class Phone
{
public:
	string m_Pname;	//�ֻ�Ʒ��

	Phone(string name)
	{
		m_Pname = name;
		cout<<"Phone�Ĺ��캯������" << endl;
	}

	~Phone()
	{
		cout << "Phone��������������" << endl;
	}
};

//����
class Person
{
public:
	string m_name; //����
	Phone m_phone;  //�ֻ�

	Person(string name, string Pname):m_name(name),m_phone(Pname)
	{
		cout<<"Person�Ĺ��캯������" << endl;
	}

	~Person()
	{
		cout<<"Person��������������" << endl;
	}
};

void Demo()
{
	Person p("����", "����");
	cout << "������" << p.m_name << endl;
	cout << "�ֻ�Ʒ�ƣ�" << p.m_phone.m_Pname << endl;
}
int main6()
{
	Demo();
	system("pause");
	return 0;;
}