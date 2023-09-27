#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person
{
public:

	T1 NameType;	//姓名
	T2 AgeType;		//年龄

	Person(T1 name, T2 age);	//有参构造
	
	void displayPerson();		//显示成员变量类型
	
	void displayType();			//显示类信息
};
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	 this->NameType = name;
	 this->AgeType = age;
}

template<class T1, class T2>
void Person<T1, T2>::displayPerson()
 {
	  cout << "NameType:" << this->NameType << endl;
	  cout << "AgeType:" << this->AgeType << endl;
 }

template<class T1, class T2>
void Person<T1, T2>::displayType()
  {
	//typeid(T1).name 能获取当前变量的类型
	cout << "NameType的类型为：" << typeid(T1).name() << endl;
	cout << "AgeType的类型为："<<typeid(T2).name() << endl;
  }

 
 