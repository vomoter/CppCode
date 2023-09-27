#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	string m_Name;
	int m_Age;

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//重载==运算符
	bool operator==(Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//重载！=运算符
	bool operator!= (Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

};
int main5()
{
	Person p1("Tom", 18);
	Person p2("Tom", 18);
	Person p3("Tim", 18);
	if (p1 == p2)
	{
		cout<<"p1和p2是相等的" << endl;
	}
	else
	{
		cout << "p1和p2不相等的" << endl;
	}
	if (p1 != p3)
	{
		cout << "p1和p3不相等的" << endl;
	}
	else
	{
		cout << "p1和p3是相等的" << endl;
	}

	system("pause");
	return 0;
}