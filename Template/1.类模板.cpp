#include<iostream>
#include<string>
using namespace std;

//类模板在模板参数列表中可以有默认参数
template<class NameType, class AgeType = int>
class Person
{
public:
	NameType m_name;	//姓名
	AgeType m_age;		//年龄

	Person(NameType name, AgeType age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void showPerson()
	{
		cout <<"姓名为："<<this->m_name<<" 年龄为："<<this->m_age << endl;
	}
};
int main01()
{
	//要在<> 中指定数据类型
	//1.类模板没有自动类型推导方式
	Person <string,int>p1("张三", 18);
	p1.showPerson();

	//2.类模板在模板参数列表中可以有默认参数
	Person <string>p2("李四",19);
	p2.showPerson();

	system("pause");
	return 0;
}