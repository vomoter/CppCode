#include<iostream>
using namespace std;

/*
	菱形继承：
	两个派生派继承同一个基类
	又与某个类同时继承着两个派生类
*/

//动物类
class Animal 
{
public :
	int m_Age;

};

/*
	利用虚继承，解决菱形继承的问题
	继承之前，加上关键字virtual变为虚继承
	Animal类称为 虚基类

*/
//羊类
class Sheep : virtual public Animal {};

//驼类
class Tuo : virtual public Animal {};

//羊驼类
class SheepTuo : public Sheep, public Tuo {};

int main()
{
	SheepTuo st;
	//当菱形继承时，两个父类拥有相同数据，需要加以作用域区分
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 19;
	cout << "Sheep::m_Age = " <<st.Sheep::m_Age<< endl;
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout<<st.m_Age<<endl;

	system("pause");
	return 0;
}