#include<iostream>
using namespace std;

//		浅拷贝：简单的赋值拷贝操作
//		深拷贝：在堆区重新申请空间，进行拷贝操作
class Person
{
public:
	int m_age;	//年龄
	int *m_heigh;	//身高
	
	Person()
	{
		cout << "Person 无参构造函数的调用" << endl;
	}
	
	Person(int age,int heigh)
	{
		m_age = age;
		m_heigh = new int(heigh);
		cout << "Person 有参构造函数的调用" << endl;
	}

	Person(const Person& p)
	{
		m_age = p.m_age;

		//深拷贝操作，重新在堆区开辟空间，防止析构重复释放一块地址
		m_heigh = new int(*p.m_heigh);
		cout << "Person 拷贝造函数的调用" << endl;
	}

	~Person()
	{
		//析构代码，将堆区开辟数据做释放操作
		if (m_heigh != NULL)
		{
			delete m_heigh;
			m_heigh = NULL;
		}
		cout << "Person 析构函数的调用" << endl;
	}

};

void demo()
{
	Person p1(19,175);
	cout<<"p1的年龄为："<<p1.m_age <<"身高为:"<<&p1.m_heigh << endl;
	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age <<"身高为："<<&p2.m_heigh << endl;


}
int main4()
{
	demo();

	system("pause");
	return 0;
}