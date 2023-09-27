#include<iostream>
using namespace std;



/*
	抽象类特点：
	1.无法实例化对象
	2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/

class Base
{
public:
	//纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0
	//当类中有了纯虚函数，这个类也称为抽象类
	virtual void func() = 0;

};

class Son : public Base
{
public:
	void func()
	{
		cout<<"子类重写父类纯虚函数" << endl;
	}

};
int main3()
{
//	Base b;	//抽象类无法实例化对象	
	Son s;
	s.func();

	system("pause");
	return 0;
}