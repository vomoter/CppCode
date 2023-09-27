#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Person
{
public:
	string m_Name;	//����
	int m_Age;		//����

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
};

void showPerson(Person& p)
{
	cout << "name: " << p.m_Name;
	cout << "\tage:" << p.m_Age;
	cout << endl;
}
//�������������ȫ�ֺ���
ostream& operator<<(ostream& cout, Person p)
{
	cout << "name: " << p.m_Name;
	cout << "\tage:" << p.m_Age;
	return cout<<"\n";
}

//����Զ�����������
void test()
{
	vector<Person> P;		//Person������
	Person p1("����", 18);
	Person p2("����", 19);
	P.push_back(p1);
	P.push_back(p2);

	//ͨ�����������������е�����
	vector<Person>::iterator Begin = P.begin();	//��ʼ��������ָ�������е�һ��Ԫ��
	vector<Person>::iterator End = P.end();		//������������ָ���������һ��Ԫ�ص���һ��λ��

	//��һ�ַ�������
	cout << "��һ�ַ�������:" << endl;
	while (Begin != End)
	{
		cout << *Begin;
		Begin++;
	}
	cout << "\n�ڶ��ַ�������:" << endl;
	//�ڶ��ַ�������
	for (vector<Person>::iterator it = P.begin(); it != P.end(); it++)
	{
		cout << *it;
	}

	cout << "\n�����ַ�������:" << endl;
	for_each(P.begin(), P.end(), showPerson);
	cout << endl;
}

//����Զ�����������ָ��
void test2()
{
	vector<Person *> P;		//Person��ָ������
	Person p1("����", 18);
	Person p2("����", 19);
	Person p3("����",20);
	P.push_back(&p1);
	P.push_back(&p2);
	P.push_back(&p3);

	for (vector<Person *>::iterator it = P.begin(); it != P.end(); it++)
	{
		cout << "name: " << (*it)->m_Name;
		cout << "\tage:" << (*it)->m_Age;
		cout << endl;
	}
}
int main2()
{
	test2();

	system("pause");
	return 0;
}