#include<iostream>
#include<string>
using namespace std;

class House;
class GoodFriend
{
public:
	void visit();	//让visit函数可以访问House中的私有属性
	void visit2();	//让visit函数不能访问House中的私有属性
	GoodFriend();
	House*  house;
};

class House
{
	//GoodFriend类是House类的友元，可以访问本类私有成员
	friend void GoodFriend::visit();
private:
	string m_Bedroom;	//卧室
public:
	string m_SittingRoom;	//客厅

	House();//类内定义成员函数

};

//类外写成员函数
House::House()
{
	m_SittingRoom = "客厅";
	m_Bedroom = "卧室";
}

GoodFriend::GoodFriend()
{
	//创建建筑物对象
	house = new House;

}
void GoodFriend::visit()
{
	cout << "visit函数 正在访问：" << house->m_SittingRoom << endl;
	cout << "visit函数 正在访问：" << house->m_Bedroom << endl;//GoodFriend类是House类的友元，可以访问本类私有成员


}
void GoodFriend::visit2()
{
	cout << "visit2函数 正在访问：" << house->m_SittingRoom << endl;
	//cout << "visit函数 正在访问：" << house->m_Bedroom << endl;
}
int main()
{
	GoodFriend g;
	g.visit();
	g.visit2();

	system("pause");
	return 0;
}