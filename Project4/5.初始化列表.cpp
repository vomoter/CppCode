#include<iostream>
using namespace std;

//初始化列表
class Person
{
public:

	int m_A;
	int m_B;
	int m_C;

	//传统初始化列表
/*	Person(int a, int b, int c)
	{
		m_A = a;
		m_B = b;
		m_C = c;
	
	}*/

	//初始化列表
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{
	
	}
};

int main5()
{

	Person p(10, 20, 30);
	cout<<"p.m_A ="<<p.m_A <<"\np.m_B ="<<p.m_B<<"\np.m_C ="<<p.m_C << endl;

	system("pause");
	return 0;
}