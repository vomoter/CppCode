#include<iostream>
using namespace std;
/*
	һ��Ĭ������£�c++���������ٸ�һ�������3������
		1.Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
		2.Ĭ�������������޲Σ�������Ϊ�գ�
		3.Ĭ�Ͽ������캯���������Խ���ֵ����


	�������캯�����ù������£�
		1.����û������вι��캯����c++�����ṩ�޲ι��죬�����ṩĬ�Ͽ�������
		2.����û����忽�����캯����c++�������ṩ�������캯��
*/
class Person
{
public:
	int m_age;

	Person()
	{
		cout << "Person �޲ι��캯���ĵ���" << endl;
	}

	Person(int a)
	{
		m_age = a;
		cout << "Person �вι��캯���ĵ���" << endl;
	}

	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person �����캯���ĵ���" << endl;
	}

	~Person()
	{
		cout << "Person ���������ĵ���" << endl;
	}

};

void text1()
{
	
	Person p1(20);
	Person p2(p1);
	cout<<"p2������Ϊ:"<<p2.m_age<< endl;


}

//��.1
void text2()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2������Ϊ:" << p2.m_age << endl;

}

int main3()
{
	text2();

	system("pause");
	return 0;
}