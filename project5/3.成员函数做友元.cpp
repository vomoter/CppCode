#include<iostream>
#include<string>
using namespace std;

class House;
class GoodFriend
{
public:
	void visit();	//��visit�������Է���House�е�˽������
	void visit2();	//��visit�������ܷ���House�е�˽������
	GoodFriend();
	House*  house;
};

class House
{
	//GoodFriend����House�����Ԫ�����Է��ʱ���˽�г�Ա
	friend void GoodFriend::visit();
private:
	string m_Bedroom;	//����
public:
	string m_SittingRoom;	//����

	House();//���ڶ����Ա����

};

//����д��Ա����
House::House()
{
	m_SittingRoom = "����";
	m_Bedroom = "����";
}

GoodFriend::GoodFriend()
{
	//�������������
	house = new House;

}
void GoodFriend::visit()
{
	cout << "visit���� ���ڷ��ʣ�" << house->m_SittingRoom << endl;
	cout << "visit���� ���ڷ��ʣ�" << house->m_Bedroom << endl;//GoodFriend����House�����Ԫ�����Է��ʱ���˽�г�Ա


}
void GoodFriend::visit2()
{
	cout << "visit2���� ���ڷ��ʣ�" << house->m_SittingRoom << endl;
	//cout << "visit���� ���ڷ��ʣ�" << house->m_Bedroom << endl;
}
int main()
{
	GoodFriend g;
	g.visit();
	g.visit2();

	system("pause");
	return 0;
}