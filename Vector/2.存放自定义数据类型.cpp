#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Person
{
public:
	string m_Name;	//姓名
	int m_Age;		//年龄

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
};

void showPerson(Person& p)
{
	cout << "name: " << p.m_Name;
	cout << "\tage:" << p.m_Age;
	cout << endl;
}
//左移运算符重载全局函数
ostream& operator<<(ostream& cout, Person p)
{
	cout << "name: " << p.m_Name;
	cout << "\tage:" << p.m_Age;
	return cout<<"\n";
}

//存放自定义数据类型
void test()
{
	vector<Person> P;		//Person类容器
	Person p1("张三", 18);
	Person p2("李四", 19);
	P.push_back(p1);
	P.push_back(p2);

	//通过迭代器访问容器中的数据
	vector<Person>::iterator Begin = P.begin();	//起始迭代器，指向容器中第一个元素
	vector<Person>::iterator End = P.end();		//结束迭代器，指向容器最后一个元素的下一个位置

	//第一种方法遍历
	cout << "第一种方法遍历:" << endl;
	while (Begin != End)
	{
		cout << *Begin;
		Begin++;
	}
	cout << "\n第二种方法遍历:" << endl;
	//第二种方法遍历
	for (vector<Person>::iterator it = P.begin(); it != P.end(); it++)
	{
		cout << *it;
	}

	cout << "\n第三种方法遍历:" << endl;
	for_each(P.begin(), P.end(), showPerson);
	cout << endl;
}

//存放自定义数据类型指针
void test2()
{
	vector<Person *> P;		//Person类指针容器
	Person p1("张三", 18);
	Person p2("李四", 19);
	Person p3("王五",20);
	P.push_back(&p1);
	P.push_back(&p2);
	P.push_back(&p3);

	for (vector<Person *>::iterator it = P.begin(); it != P.end(); it++)
	{
		cout << "name: " << (*it)->m_Name;
		cout << "\tage:" << (*it)->m_Age;
		cout << endl;
	}
}
int main2()
{
	test2();

	system("pause");
	return 0;
}