#include<iostream>
using namespace std;

//		ǳ�������򵥵ĸ�ֵ��������
//		������ڶ�����������ռ䣬���п�������
class Person
{
public:
	int m_age;	//����
	int *m_heigh;	//���
	
	Person()
	{
		cout << "Person �޲ι��캯���ĵ���" << endl;
	}
	
	Person(int age,int heigh)
	{
		m_age = age;
		m_heigh = new int(heigh);
		cout << "Person �вι��캯���ĵ���" << endl;
	}

	Person(const Person& p)
	{
		m_age = p.m_age;

		//��������������ڶ������ٿռ䣬��ֹ�����ظ��ͷ�һ���ַ
		m_heigh = new int(*p.m_heigh);
		cout << "Person �����캯���ĵ���" << endl;
	}

	~Person()
	{
		//�������룬�����������������ͷŲ���
		if (m_heigh != NULL)
		{
			delete m_heigh;
			m_heigh = NULL;
		}
		cout << "Person ���������ĵ���" << endl;
	}

};

void demo()
{
	Person p1(19,175);
	cout<<"p1������Ϊ��"<<p1.m_age <<"���Ϊ:"<<&p1.m_heigh << endl;
	Person p2(p1);
	cout << "p2������Ϊ��" << p2.m_age <<"���Ϊ��"<<&p2.m_heigh << endl;


}
int main4()
{
	demo();

	system("pause");
	return 0;
}