#include<iostream>
using namespace std;

/*
	三种继承:
		公共继承
		保护继承
		私有继承
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

//公共继承
class Son1 : public Base
{
public:
	void func()
	{
		m_A = 10;	//父类中的公共权限成员，到子类中依然是公共权限
		m_B = 20;	//父类中的保护权限成员，到子类中依然是保护权限
		//	m_C = 30;	//父类中的私有权限成员，子类不可访问

		cout << m_A << "\t" << m_B << endl;
	}

};

class Son2 : protected Base
{
public:
	void func()
	{
		m_A = 10;	//父类中公共成员，到子类中变为保护权限
		m_B = 20;	//父类中保护成员，到子类中变为保护权限
//		m_C = 30;	//父类中的私有权限成员，子类不可访问
	
		cout << m_A << "\t" << m_B << endl;
	}
};

//私有继承
class Son3 : private Base
{
public:
	void func()
	{
		m_A = 10;	//父类中公共成员，到子类中变为私有权限
		m_B = 20;	//父类中保护成员，到子类中变为私有权限
	//	m_C = 30;	//父类中的私有权限成员，子类不可访问

		cout << m_A << "\t" << m_B << endl;
	}
};
int main1()
{
	Son1 s1;
	s1.m_A = 100;
//	s1.m_B = 200;	m_B在Son1中是保护权限，类外访问不到
	cout<<s1.m_A<<endl;
	s1.func();

	cout<<"--------------------" << endl;
	Son2 s2;
	//	m_A,m_B在Son2中是保护权限，类外访问不到
	//s2.m_A = 100;
	//	s2.m_B = 200;	
	s2.func();

	cout << "--------------------" << endl;
	Son3 s3;
	//	m_A,m_B在Son3中是私有权限，类外访问不到
	//s3.m_A = 100;
	//s3.m_B = 200;
	s3.func();

	system("pause");
	return 0;
}