#include<iostream>
#include<string>
using namespace std;

//手机类
class Phone
{
public:
	string m_Pname;	//手机品牌

	Phone(string name)
	{
		m_Pname = name;
		cout<<"Phone的构造函数调用" << endl;
	}

	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}
};

//人类
class Person
{
public:
	string m_name; //姓名
	Phone m_phone;  //手机

	Person(string name, string Pname):m_name(name),m_phone(Pname)
	{
		cout<<"Person的构造函数调用" << endl;
	}

	~Person()
	{
		cout<<"Person的析构函数调用" << endl;
	}
};

void Demo()
{
	Person p("张三", "菠萝");
	cout << "姓名：" << p.m_name << endl;
	cout << "手机品牌：" << p.m_phone.m_Pname << endl;
}
int main6()
{
	Demo();
	system("pause");
	return 0;;
}