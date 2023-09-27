#include<iostream>
#include<string>
using namespace std;

//多态在使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码块
//解决方式：将父类中的析构函数改为虚析构或者纯虚析构
/*
	虚构和纯虚析构共性：
	1.可以解决父类指针释放子类对象
	2.都需要具体的函数实现

	虚析构和纯虚构区别：
	如果是纯虚析构，该类属于抽象类，无法实例化对象

*/

//水果类
class Fruit
{
public:
	Fruit()
	{
		cout << "Fruit类的构造函数调用" << endl;
	}

	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
/*	virtual ~Fruit()
	{
		cout << "Friuit类的虚析构函数调用" << endl;
	}*/

	//纯虚析构类内声明，类外实现
	//有了纯虚析构后，这个类也属于抽象类，无法实例化对象
	virtual ~Fruit() = 0;

	virtual void Taste() = 0;
};

Fruit::~Fruit()
{
	cout << "Friuit类的纯虚析构函数调用" << endl;
}

//苹果类
class Apple : public Fruit
{
public:
	string *name;

	Apple(string name)
	{
		cout << "Apple类的构造函数调用" << endl;
		this->name = new string(name);
	}

	~Apple()
	{
		cout << "Apple类的析构函数调用" << endl;
		if (name != NULL)
		{
			delete name;
			name = NULL;
		}
	}
	void Taste()
	{
		cout <<*name<< "苹果味道好极了" << endl;
	}
};

void test01()
{
	Fruit * fruit = new Apple("红富士");
	fruit->Taste();
	delete fruit;
}
int main5()
{
	test01();
	/*
		总结：
		1.虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
		2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
		3.拥有纯虚构函数的类也属于抽象类
	
	*/
	system("pause");
	return 0;
}