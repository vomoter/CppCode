#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout<<"Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class Test
{
public:
	T obj;	//��Ա����

	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
	void show1()
	{
		obj.showPerson1();
	}

	void show2()
	{
		obj.showPerson2();
	}

};
int main2()
{
	Test<Person1> p1;
	p1.show1();
//	p1.show2();		//�������ִ���˵����������ʱ�Ż�ȥ������Ա����

	Test<Person2> p2;
//	p2.show1();
	p2.show2();
	system("pause");
	return 0;
}