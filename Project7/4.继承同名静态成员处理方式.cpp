#include<iostream>
using namespace std;

/*
	静态成员和非静态成员出现同名,处理方式一致
	访问子类同名成员，直接访问即可。 
	访问父类 同名成员，需要加作用域
*/
class A
{
public:
	//静态变量，类内声明，类外初始化
	static int m_A;

	static void func()
	{
		cout<<"父类下 m_A =" <<m_A<< endl;
	}

	static void func(int num)
	{
		cout<<"num ="<<num << endl;
	}
};
int A::m_A = 100;
class B : public A
{
public:
	static int m_A;
	static void func()
	{
		cout << "子类下 m_A =" << m_A << endl;

	}

};
int B::m_A = 200;

int main4()
{

	//同名静态成员属性
	//1、通过对象访问
	cout<<"提供对象访问" << endl;
	B b;
	cout << "子类下 m_A = " << b.m_A << endl;
	//如果通过子类对象，访问父类中同名成员，需要加作用域 ::
	cout << "父类下 m_A = " << b.A::m_A << endl;

	//2.通过类名访问
	cout<<"通过类名访问" << endl;
	cout << "子类下 m_A = "<<B::m_A << endl;
	cout << "父类下 m_A = " <<B::A::m_A << endl;


	//同名静态成员函数
	//1、通过对象访问
	cout << "\n提供对象访问" << endl;
	B b2;
	b2.func();
	b2.A::func();

	//2.通过类名访问
	cout << "通过类名访问" << endl;
	B::func();
	B::A::func();

	//子类出现和父类同名静态成员函数，也会隐藏父类中所有同名函数
	//如果想访问父类中被隐藏的同名成员，需要加作用域
	B::A::func(100);


	system("pause");
	return 0;
}