#include<iostream>
using namespace std;

class Person
{
	//重载函数做友元，可以访问该类的私有成员
	friend ostream& operator<<(ostream& cout, Person& p1);
private:
	int m_A;
	int m_B;
	//利用成员函数重载 左移运算符    p.operator<<cout 简化为 p<<cout
	//不会利用成员函数重载<<运算符   因为无法实现cout在左侧
public :
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
};

//只能用全局函数来重载左移运算符
ostream &operator<<(ostream &cout, Person &p1)
{
	cout << "m_A = " << p1.m_A << ", m_B = " << p1.m_B;
	return cout;
}
int main2()
{
	Person p1(10, 10);
	Person p2(10, 20);
	cout << p1 <<endl;
	cout << p2 <<endl;

	system("pause");
	return 0;
}