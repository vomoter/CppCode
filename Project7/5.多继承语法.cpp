#include<iostream>
using namespace std;

/*
	C++允许一个类继承多个类
	语法 class 子类：继承方式 父类1，继承方式 父类2 ……
	多继承可能会引发父类中有同名成员出现，需要加作用域区分

	C++实际开发中不建议用多继承

*/

class Base1
{
public:
	int m_A ;

	Base1()
	{
		m_A = 100;
	}

};
class Base2
{
public:
	int m_A;

	Base2()
	{
		m_A = 200;
	}

};
//子类继承Base1和Base2
class So : public Base1, public Base2
{
public:
	int m_C;
	So()
	{
		m_C = 300;
	}

};

int main5()
{
	So s1;
	cout<<"sizeof So:"<<sizeof(s1) << endl;
	//当父类出现同名成员，需要加作用域区分
	cout<<"Base1::m.A ="<<s1.Base1::m_A << endl;
	cout<<"Base2::m.A ="<<s1.Base2::m_A << endl;

	system("pause");
	return 0;
}