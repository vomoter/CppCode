#include<iostream>
using namespace std;
	
/*	���ַ��෽ʽ��
		��������Ϊ���вι�����޲ι���
		�����ͷ�Ϊ����ͨ����͹��쿽��
	���ֵ��÷�ʽ��
		���ŷ�����ʾ������ʽת����
*/
class Person
{
public:
	int m_age;

	//�޲ι���:
	Person() 
	{
		cout << "Person �޲ι��캯���ĵ���" << endl;
	}
	//�вι���
	Person(int a)
	{
		m_age = a;
		cout << "Person �вι��캯���ĵ���" << endl;
	}

	//�������캯��
	Person(const Person& p)
	{
		//������Ķ������ϵ��������ԣ��������Լ�����
		m_age = p.m_age;
		cout << "Person �����캯���ĵ���"<< endl;
	
	}

	//��������
	~Person()
	{
		cout << "Person ���������ĵ���" << endl;
	}

};

//���ú���
void test()
{
	//1.���ŷ�
//	Person p1;	//Ĭ�Ϲ��캯������
//	Person p2(10);  //�вι��캯��
//	Person p3(p2);  //�������캯��

//	cout<<"p2������Ϊ��" <<p2.m_age<< endl;
//	cout<<"p3������Ϊ��" <<p3.m_age<< endl;
	
	/*
	ע�����
		����Ĭ�Ϲ��캯��ʱ�򣬲�Ҫ�ӣ���
		��Ϊ����һ�д��룬����������Ϊ��һ��������������������Ϊ�ڴ�������
	*/
//	Person p1();
//	void func();
	
	//2.��ʾ��
/*	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);
	cout << "p2������Ϊ��" << p2.m_age << endl;
	cout<<"p3������Ϊ��" <<p3.m_age<< endl;
*/
//	Person(20); //�������󣬵�ǰ��ִ�н�����ϵͳ������������������
	//ע��2����Ҫ���ÿ������캯��������ʼ����������
//	Person(p3);
	//Person(p3) == Person p3
	
	//3.��ʽת����
	Person p4 = 10;	//�൱�� Person p4 = Person(10);
	Person p5 = p4;	//��������
}

int main2()
{

	test();
	system("pause");
	return 0;
}