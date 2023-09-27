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
	cout<<"子类下 m_A = "<<s.m_A << endl;
	//如果提供子类对象，访问父类中同名成员，需要加作用域 ::
	cout << "父类下 m_A = " << s.Fu::m_A << endl;

	s.func();
	//如果提供子类对象，访问父类中同名函数，需要加作用域 ::
	s.Fu::func();

	system("pause");
	return 0;
}