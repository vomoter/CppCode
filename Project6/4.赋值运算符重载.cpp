#include<iostream>
using namespace std;

/*
	c++���������ٸ�һ�������4������
		1.Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
		2.Ĭ�������������޲Σ�������Ϊ�գ�
		3.Ĭ���������캯���������Խ���ֵ����
		4.��ֵ����� operator= ,�����Խ���ֵ����
		�������������ָ�����������ֵ����ʱҲ�������ǳ��������
*/
class Person
{
public:
	int *m_Age;

	Person(int age)
	{
		this->m_Age = new int(age);
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person &operator=(Person& p)
	{
		//�������ṩǳ����
		//m_Age = p.m_Age;

		//Ӧ�����ж��Ƿ��������ڶ�������������ͷŸо���Ȼ�������
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);

		//���ض�����
		return *this;
	}
};
int main4()
{
	Person p1(19);
	Person p2(20);
	Person p3(30);
	p3=p2 = p1;	//��ֵ����
	cout << "p1.m_Age = " << *p1.m_Age << endl;
	cout << "p2.m_Age = " << *p2.m_Age << endl;
	cout << "p3.m_Age = " << *p2.m_Age << endl;

	system("pause");
	return 0;
}