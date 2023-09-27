#include<iostream>
#include<string>
using namespace std;

//��ǰ�ñ�����֪��Person��Ĵ���
template<class T1, class T2>
class Person;

//����ʵ��
template<class T1, class T2>
void showPerson2(Person<T1, T2> p)
{
	cout << "����ʵ��" << endl;
	cout << "Name:" << p.m_name << endl;
	cout << "Age:" << p.m_age << endl;
}

template<class T1,class T2>
class Person
{
	//ȫ�ֺ���������ʵ��
	friend void showPerson(Person<T1,T2> p)
	{
		cout << "����ʵ��" << endl;
		cout << "Name:" << p.m_name << endl;
		cout << "Age:" << p.m_age<< endl;
	}
	//ȫ�ֺ���������ʵ��
	//��һ����ģ��Ĳ����б�
	//���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void showPerson2<>(Person<T1, T2> p);
private:
	T1 m_name;
	T2 m_age;

public:
	Person(T1 name, T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}
};
int main4()
{
	Person<string,int> p1("����",19);
	showPerson(p1);
	showPerson2(p1);

	system("pause");
	return 0;
}

