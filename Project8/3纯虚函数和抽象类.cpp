#include<iostream>
using namespace std;



/*
	�������ص㣺
	1.�޷�ʵ��������
	2.���������д�������еĴ��麯��������Ҳ���ڳ�����
*/

class Base
{
public:
	//���麯���﷨��virtual ����ֵ���� ������ �������б�= 0
	//���������˴��麯���������Ҳ��Ϊ������
	virtual void func() = 0;

};

class Son : public Base
{
public:
	void func()
	{
		cout<<"������д���ി�麯��" << endl;
	}

};
int main3()
{
//	Base b;	//�������޷�ʵ��������	
	Son s;
	s.func();

	system("pause");
	return 0;
}