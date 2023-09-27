#include<iostream>
#include<string>
using namespace std;

//友元：目的让一个函数或者类访问另一个类中私有成员

/*class Building
{
//GoodGay全局函数是Building的友元，可以访问Building中私有成员
friend void goodGay(Building* building);
private:
	string m_Bedroom;	//卧室
public:
	string m_SittingRoom;	//客厅

	Building()
	{
		m_SittingRoom = "客厅";
		m_Bedroom = "卧室";
	}

};

//全局函数
void goodGay(Building* building)
{
	cout<<"好基友全局函数 正在访问："<<building->m_SittingRoom << endl;
	cout<<"好基友全局函数 正在访问："<<building->m_Bedroom<<endl;
}

int main1()
{
	Building building;
	goodGay(&building);


	
	system("pause");
	return 0;
}*/