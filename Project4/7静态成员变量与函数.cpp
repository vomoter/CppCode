#include<iostream>
using namespace std;

//��̬��Ա����
class Person
{
public:
	/*
		1.���ж��󶼹���ͬһ������
		2.����׶ξͷ����ڴ�
		3.���������������ʼ������
	*/
	static int m_A;	//��̬��Ա����
	int m_C;		//�Ǿ�̬��Ա����

	/*
	��̬��Ա����:
		1.���ж�����ͬһ������
		2.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	
	*/
	static void func()
	{
		m_A = 200;	//��̬��Ա�������Է��� ��̬��Ա����
		//m_C = 200;  �Ǿ�̬��Ա���������Է��� ��̬��Ա����
		cout<<"��̬��Ա��������" <<"m_A = "<<m_A << endl;
	
	}

	//��̬��Ա����Ҳ�з���Ȩ��
private:
	static int m_B;

};
int Person::m_A = 100;
int main()
{
	
	Person p1;
	//��̬��Ա����
	//1.ͨ��������з���
	cout << "m_A = "<<p1.m_A << endl;
	//2.ͨ���������з���
	cout<< "m_A = " << Person::m_A<<endl;


	Person p2;
	//1.ͨ��������з���
	p2.func();
	//2.ͨ���������з���
	Person::func();
	

	system("pause");
	return 0;
}