#include<iostream>
#include<string>
using namespace std;

//提前让编译器知道Person类的存在
template<class T1, class T2>
class Person;

//类外实现
template<class T1, class T2>
void showPerson2(Person<T1, T2> p)
{
	cout << "类外实现" << endl;
	cout << "Name:" << p.m_name << endl;
	cout << "Age:" << p.m_age << endl;
}

template<class T1,class T2>
class Person
{
	//全局函数，类内实现
	friend void showPerson(Person<T1,T2> p)
	{
		cout << "类内实现" << endl;
		cout << "Name:" << p.m_name << endl;
		cout << "Age:" << p.m_age<< endl;
	}
	//全局函数，类外实现
	//加一个空模板的参数列表
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	friend void showPerson2<>(Person<T1, T2> p);
private:
	T1 m_name;
	T2 m_age;

public:
	Person(T1 name, T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}
};
int main4()
{
	Person<string,int> p1("张三",19);
	showPerson(p1);
	showPerson2(p1);

	system("pause");
	return 0;
}

