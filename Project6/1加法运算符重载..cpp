#include<iostream>
using namespace std;

//��������أ������е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
//�ӷ���������أ�ʵ���Զ�������������ӵ�����


class Person
{
public:
	int m_A;
	int m_B;

	//1.��Ա��������+��
	Person operator+(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
	return temp;
	}
};



//2.ȫ�ֺ�������+��
Person operator+(Person &p1, Person &p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;

}
int main1()
{
	Person p1, p2;
	p1.m_A = 10, p1.m_B = 10;
	p2.m_A = 20, p2.m_B = 20;
	//��Ա�������ر��ʵ���
	  Person p3 = p1.operator+(p2);	//�൱�� p3 = p1 + p2;
	  cout << "m_A = " << p3.m_A << "\nm_B = " << p3.m_B << endl;

	  Person a1, a2;
	  a1.m_A = 10, a1.m_B = 10;
	  a2.m_A = 10, a2.m_B = 10;
	//ȫ�ֺ������ر��ʵ���
	Person a3 = operator+(a1, a2);  //�൱�� p3 = p1 + p2;

	cout << "\nm_A = " << a3.m_A << "\nm_B = " << a3.m_B << endl;



	system("pause");
	return 0;
}