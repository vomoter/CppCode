#include<iostream>
using namespace std;

/*
	C++����һ����̳ж����
	�﷨ class ���ࣺ�̳з�ʽ ����1���̳з�ʽ ����2 ����
	��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������

	C++ʵ�ʿ����в������ö�̳�

*/

class Base1
{
public:
	int m_A ;

	Base1()
	{
		m_A = 100;
	}

};
class Base2
{
public:
	int m_A;

	Base2()
	{
		m_A = 200;
	}

};
//����̳�Base1��Base2
class So : public Base1, public Base2
{
public:
	int m_C;
	So()
	{
		m_C = 300;
	}

};

int main5()
{
	So s1;
	cout<<"sizeof So:"<<sizeof(s1) << endl;
	//���������ͬ����Ա����Ҫ������������
	cout<<"Base1::m.A ="<<s1.Base1::m_A << endl;
	cout<<"Base2::m.A ="<<s1.Base2::m_A << endl;

	system("pause");
	return 0;
}