#include<iostream>
#include<string>
using namespace std;

class MyPrint
{
public:
	void operator()(string str)
	{
		cout<<str<< endl;
	}
};

class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	MyPrint m;
	//由于使用起来非常类似于函数调用，因此称为仿函数，非常灵活，没有固定写法
	//以下两句等价
	m("Hello World!");
	m.operator()("Hello World!");

	//函数运算符重载实现加法
	MyAdd myadd;
	int result=myadd(10, 20);
	cout<<result<<endl;
	//匿名函数对象
	cout << MyAdd()(100, 200) << endl;

	system("pause");
	return 0;
}