#include<iostream>
using namespace std;

//静态成员变量
class Person
{
public:
	/*
		1.所有对象都共享同一份数据
		2.编译阶段就分配内存
		3.类内声明，类外初始化操作
	*/
	static int m_A;	//静态成员变量
	int m_C;		//非静态成员变量

	/*
	静态成员函数:
		1.所有对象共享同一个函数
		2.静态成员函数只能访问静态成员变量
	
	*/
	static void func()
	{
		m_A = 200;	//静态成员函数可以访问 静态成员变量
		//m_C = 200;  非静态成员函数不可以访问 静态成员变量
		cout<<"静态成员函数调用" <<"m_A = "<<m_A << endl;
	
	}

	//静态成员变量也有访问权限
private:
	static int m_B;

};
int Person::m_A = 100;
int main()
{
	
	Person p1;
	//静态成员变量
	//1.通过对象进行访问
	cout << "m_A = "<<p1.m_A << endl;
	//2.通过类名进行访问
	cout<< "m_A = " << Person::m_A<<endl;


	Person p2;
	//1.通过对象进行访问
	p2.func();
	//2.通过类名进行访问
	Person::func();
	

	system("pause");
	return 0;
}