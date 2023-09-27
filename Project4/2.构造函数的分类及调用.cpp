#include<iostream>
using namespace std;
	
/*	两种分类方式：
		按参数分为：有参构造和无参构造
		按类型分为：普通构造和构造拷贝
	三种调用方式：
		括号法、显示法、隐式转换法
*/
class Person
{
public:
	int m_age;

	//无参构造:
	Person() 
	{
		cout << "Person 无参构造函数的调用" << endl;
	}
	//有参构造
	Person(int a)
	{
		m_age = a;
		cout << "Person 有参构造函数的调用" << endl;
	}

	//拷贝构造函数
	Person(const Person& p)
	{
		//将传入的对象身上的所有属性，拷贝到自己身上
		m_age = p.m_age;
		cout << "Person 拷贝造函数的调用"<< endl;
	
	}

	//析构函数
	~Person()
	{
		cout << "Person 析构函数的调用" << endl;
	}

};

//调用函数
void test()
{
	//1.括号法
//	Person p1;	//默认构造函数调用
//	Person p2(10);  //有参构造函数
//	Person p3(p2);  //拷贝构造函数

//	cout<<"p2的年龄为：" <<p2.m_age<< endl;
//	cout<<"p3的年龄为：" <<p3.m_age<< endl;
	
	/*
	注意事项：
		调用默认构造函数时候，不要加（）
		因为下面一行代码，编译器会认为是一个函数的声明，不会认为在创建对象
	*/
//	Person p1();
//	void func();
	
	//2.显示法
/*	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);
	cout << "p2的年龄为：" << p2.m_age << endl;
	cout<<"p3的年龄为：" <<p3.m_age<< endl;
*/
//	Person(20); //匿名对象，当前行执行结束后，系统会立即回收匿名函数
	//注意2：不要利用拷贝构造函数，来初始化匿名对象
//	Person(p3);
	//Person(p3) == Person p3
	
	//3.隐式转换法
	Person p4 = 10;	//相当于 Person p4 = Person(10);
	Person p5 = p4;	//拷贝构造
}

int main2()
{

	test();
	system("pause");
	return 0;
}