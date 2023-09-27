#include<iostream>
using namespace std;
/*
	一、默认情况下，c++编译器至少给一个类添加3个函数
		1.默认构造函数(无参，函数体为空)
		2.默认析构函数（无参，函数体为空）
		3.默认拷贝构造函数，对属性进行值拷贝


	二、构造函数调用规则如下：
		1.如果用户定义有参构造函数，c++不在提供无参构造，但会提供默认拷贝构造
		2.如果用户定义拷贝构造函数，c++不会再提供其他构造函数
*/
class Person
{
public:
	int m_age;

	Person()
	{
		cout << "Person 无参构造函数的调用" << endl;
	}

	Person(int a)
	{
		m_age = a;
		cout << "Person 有参构造函数的调用" << endl;
	}

	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "Person 拷贝造函数的调用" << endl;
	}

	~Person()
	{
		cout << "Person 析构函数的调用" << endl;
	}

};

void text1()
{
	
	Person p1(20);
	Person p2(p1);
	cout<<"p2的年龄为:"<<p2.m_age<< endl;


}

//二.1
void text2()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2的年龄为:" << p2.m_age << endl;

}

int main3()
{
	text2();

	system("pause");
	return 0;
}