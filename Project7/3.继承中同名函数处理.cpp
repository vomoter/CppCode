#include<iostream>
using namespace std;

class Fu
{
public :
	int m_A;

	Fu()
	{
		m_A = 100;
	}
	void func()
	{
		cout<<"m_A = "<<m_A << endl;
	}
};

class Zi : public Fu
{
public:
	int m_A;

	Zi()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "m_A = " << m_A << endl;
	}
};
int main3()
{
	Zi s;
	cout<<"������ m_A = "<<s.m_A << endl;
	//����ṩ������󣬷��ʸ�����ͬ����Ա����Ҫ�������� ::
	cout << "������ m_A = " << s.Fu::m_A << endl;

	s.func();
	//����ṩ������󣬷��ʸ�����ͬ����������Ҫ�������� ::
	s.Fu::func();

	system("pause");
	return 0;
}