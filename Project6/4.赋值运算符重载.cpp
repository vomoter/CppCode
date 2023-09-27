#include<iostream>
using namespace std;

/*
	c++编译器至少给一个类添加4个函数
		1.默认构造函数（无参，函数体为空）
		2.默认析构函数（无参，函数体为空）
		3.默认析构构造函数，对属性进行值拷贝
		4.赋值运算符 operator= ,对属性进行值拷贝
		如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
*/
class Person
{
public:
	int *m_Age;

	Person(int age)
	{
		this->m_Age = new int(age);
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person &operator=(Person& p)
	{
		//编译器提供浅拷贝
		//m_Age = p.m_Age;

		//应该先判断是否有属性在堆区，如果有先释放感觉，然后在深拷贝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);

		//返回对象本身
		return *this;
	}
};
int main4()
{
	Person p1(19);
	Person p2(20);
	Person p3(30);
	p3=p2 = p1;	//赋值操作
	cout << "p1.m_Age = " << *p1.m_Age << endl;
	cout << "p2.m_Age = " << *p2.m_Age << endl;
	cout << "p3.m_Age = " << *p2.m_Age << endl;

	system("pause");
	return 0;
}