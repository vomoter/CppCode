#include<iostream>
using namespace std;

/*
	��̬��Ա�ͷǾ�̬��Ա����ͬ��,����ʽһ��
	��������ͬ����Ա��ֱ�ӷ��ʼ��ɡ� 
	���ʸ��� ͬ����Ա����Ҫ��������
*/
class A
{
public:
	//��̬���������������������ʼ��
	static int m_A;

	static void func()
	{
		cout<<"������ m_A =" <<m_A<< endl;
	}

	static void func(int num)
	{
		cout<<"num ="<<num << endl;
	}
};
int A::m_A = 100;
class B : public A
{
public:
	static int m_A;
	static void func()
	{
		cout << "������ m_A =" << m_A << endl;

	}

};
int B::m_A = 200;

int main4()
{

	//ͬ����̬��Ա����
	//1��ͨ���������
	cout<<"�ṩ�������" << endl;
	B b;
	cout << "������ m_A = " << b.m_A << endl;
	//���ͨ��������󣬷��ʸ�����ͬ����Ա����Ҫ�������� ::
	cout << "������ m_A = " << b.A::m_A << endl;

	//2.ͨ����������
	cout<<"ͨ����������" << endl;
	cout << "������ m_A = "<<B::m_A << endl;
	cout << "������ m_A = " <<B::A::m_A << endl;


	//ͬ����̬��Ա����
	//1��ͨ���������
	cout << "\n�ṩ�������" << endl;
	B b2;
	b2.func();
	b2.A::func();

	//2.ͨ����������
	cout << "ͨ����������" << endl;
	B::func();
	B::A::func();

	//������ֺ͸���ͬ����̬��Ա������Ҳ�����ظ���������ͬ������
	//�������ʸ����б����ص�ͬ����Ա����Ҫ��������
	B::A::func(100);


	system("pause");
	return 0;
}