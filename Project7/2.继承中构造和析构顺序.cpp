#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base的构造函数调用" << endl;
	}

	~Base()
	{
		cout << "Base的析构函数调用" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son的构造函数调用" << endl;
	}

	~Son()
	{
		cout << "Son的析构函数调用" << endl;
	}

};
void text()
{
	//先构造父类，再构造子类，构造的顺序与构造的顺序相反
	Son s;
}
int main2()
{
	text();

	system("pause");
	return 0;
}