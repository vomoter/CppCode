#include<iostream>
using namespace std;

//对象的初始化和清理
class Person
{
public:
	//1.构造函数， 进行初始化操作
	/*
		没有返回值，没有void
		函数名  与类名相同
		构造函数可以有参数，可以发生重载
		创建对象的时候，构造函数会自动调用。而且只调用一次
	*/
	Person()
	{
		cout<<"Person 构造函数的调用" << endl;
	}

	//2.析构函数，进行清理的操作
	/*
		没有返回值，没有void
		函数名  与类名相同
		构造函数不可以有参数，不可以发生重载
		对象在销毁的时候，构造函数会自动调用。而且只调用一次
	*/
	~Person()
	{
		cout<<"Person 析构函数的调用" << endl;
	}
};

void test1()
{
	Person p; //在栈上的数据，test1执行完毕后，释放这个对象
}

int main1()
{
//	test1();
	Person p;
	system("pause");
	return 0;
}