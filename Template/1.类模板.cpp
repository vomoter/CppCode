#include<iostream>
#include<string>
using namespace std;

//��ģ����ģ������б��п�����Ĭ�ϲ���
template<class NameType, class AgeType = int>
class Person
{
public:
	NameType m_name;	//����
	AgeType m_age;		//����

	Person(NameType name, AgeType age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void showPerson()
	{
		cout <<"����Ϊ��"<<this->m_name<<" ����Ϊ��"<<this->m_age << endl;
	}
};
int main01()
{
	//Ҫ��<> ��ָ����������
	//1.��ģ��û���Զ������Ƶ���ʽ
	Person <string,int>p1("����", 18);
	p1.showPerson();

	//2.��ģ����ģ������б��п�����Ĭ�ϲ���
	Person <string>p2("����",19);
	p2.showPerson();

	system("pause");
	return 0;
}