#include<iostream>
using namespace std;

/*
	���ּ̳�:
		�����̳�
		�����̳�
		˽�м̳�
*/


class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//�����̳�
class Son1 : public Base
{
public:
	void func()
	{
		m_A = 10;	//�����еĹ���Ȩ�޳�Ա������������Ȼ�ǹ���Ȩ��
		m_B = 20;	//�����еı���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
		//	m_C = 30;	//�����е�˽��Ȩ�޳�Ա�����಻�ɷ���

		cout << m_A << "\t" << m_B << endl;
	}

};

class Son2 : protected Base
{
public:
	void func()
	{
		m_A = 10;	//�����й�����Ա���������б�Ϊ����Ȩ��
		m_B = 20;	//�����б�����Ա���������б�Ϊ����Ȩ��
//		m_C = 30;	//�����е�˽��Ȩ�޳�Ա�����಻�ɷ���
	
		cout << m_A << "\t" << m_B << endl;
	}
};

//˽�м̳�
class Son3 : private Base
{
public:
	void func()
	{
		m_A = 10;	//�����й�����Ա���������б�Ϊ˽��Ȩ��
		m_B = 20;	//�����б�����Ա���������б�Ϊ˽��Ȩ��
	//	m_C = 30;	//�����е�˽��Ȩ�޳�Ա�����಻�ɷ���

		cout << m_A << "\t" << m_B << endl;
	}
};
int main1()
{
	Son1 s1;
	s1.m_A = 100;
//	s1.m_B = 200;	m_B��Son1���Ǳ���Ȩ�ޣ�������ʲ���
	cout<<s1.m_A<<endl;
	s1.func();

	cout<<"--------------------" << endl;
	Son2 s2;
	//	m_A,m_B��Son2���Ǳ���Ȩ�ޣ�������ʲ���
	//s2.m_A = 100;
	//	s2.m_B = 200;	
	s2.func();

	cout << "--------------------" << endl;
	Son3 s3;
	//	m_A,m_B��Son3����˽��Ȩ�ޣ�������ʲ���
	//s3.m_A = 100;
	//s3.m_B = 200;
	s3.func();

	system("pause");
	return 0;
}