#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodGay
{
public:
	void visit();	//�ιۺ���������Building�е�˽������
	GoodGay();
	Building* building;
};

class Building
{
	//GoodGay����Building�����Ԫ�����Է��ʱ���˽�г�Ա
	friend class GoodGay;
private:
	string m_Bedroom;	//����
public:
	string m_SittingRoom;	//����

	Building();//���ڶ����Ա����
	
};

//����д��Ա����
Building::Building()
{
	m_SittingRoom = "����";
	m_Bedroom = "����";
}

GoodGay::GoodGay()
{
	//�������������
	building = new Building;

}
void GoodGay::visit()
{
	cout << "visit���� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit���� ���ڷ��ʣ�" << building->m_Bedroom << endl;//GoodGay����Building�����Ԫ�����Է��ʱ���˽�г�Ա


}
int main2()
{
	GoodGay g;
	g.visit();


	system("pause");
	return 0;
}