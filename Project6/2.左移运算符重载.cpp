#include<iostream>
using namespace std;

class Person
{
	//���غ�������Ԫ�����Է��ʸ����˽�г�Ա
	friend ostream& operator<<(ostream& cout, Person& p1);
private:
	int m_A;
	int m_B;
	//���ó�Ա�������� ���������    p.operator<<cout ��Ϊ p<<cout
	//�������ó�Ա��������<<�����   ��Ϊ�޷�ʵ��cout�����
public :
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
};

//ֻ����ȫ�ֺ������������������
ostream &operator<<(ostream &cout, Person &p1)
{
	cout << "m_A = " << p1.m_A << ", m_B = " << p1.m_B;
	return cout;
}
int main2()
{
	Person p1(10, 10);
	Person p2(10, 20);
	cout << p1 <<endl;
	cout << p2 <<endl;

	system("pause");
	return 0;
}