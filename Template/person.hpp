#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person
{
public:

	T1 NameType;	//����
	T2 AgeType;		//����

	Person(T1 name, T2 age);	//�вι���
	
	void displayPerson();		//��ʾ��Ա��������
	
	void displayType();			//��ʾ����Ϣ
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
	//typeid(T1).name �ܻ�ȡ��ǰ����������
	cout << "NameType������Ϊ��" << typeid(T1).name() << endl;
	cout << "AgeType������Ϊ��"<<typeid(T2).name() << endl;
  }

 
 