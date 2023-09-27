#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodGay
{
public:
	void visit();	//参观函数，访问Building中的私有属性
	GoodGay();
	Building* building;
};

class Building
{
	//GoodGay类是Building类的友元，可以访问本类私有成员
	friend class GoodGay;
private:
	string m_Bedroom;	//卧室
public:
	string m_SittingRoom;	//客厅

	Building();//类内定义成员函数
	
};

//类外写成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_Bedroom = "卧室";
}

GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;

}
void GoodGay::visit()
{
	cout << "visit函数 正在访问：" << building->m_SittingRoom << endl;
	cout << "visit函数 正在访问：" << building->m_Bedroom << endl;//GoodGay类是Building类的友元，可以访问本类私有成员


}
int main2()
{
	GoodGay g;
	g.visit();


	system("pause");
	return 0;
}