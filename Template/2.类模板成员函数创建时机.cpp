#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout<<"Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class Test
{
public:
	T obj;	//成员函数

	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
	void show1()
	{
		obj.showPerson1();
	}

	void show2()
	{
		obj.showPerson2();
	}

};
int main2()
{
	Test<Person1> p1;
	p1.show1();
//	p1.show2();		//编译会出现错误，说明函数调用时才会去创建成员函数

	Test<Person2> p2;
//	p2.show1();
	p2.show2();
	system("pause");
	return 0;
}