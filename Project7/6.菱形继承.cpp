#include<iostream>
using namespace std;

/*
	���μ̳У�
	���������ɼ̳�ͬһ������
	����ĳ����ͬʱ�̳�������������
*/

//������
class Animal 
{
public :
	int m_Age;

};

/*
	������̳У�������μ̳е�����
	�̳�֮ǰ�����Ϲؼ���virtual��Ϊ��̳�
	Animal���Ϊ �����

*/
//����
class Sheep : virtual public Animal {};

//����
class Tuo : virtual public Animal {};

//������
class SheepTuo : public Sheep, public Tuo {};

int main()
{
	SheepTuo st;
	//�����μ̳�ʱ����������ӵ����ͬ���ݣ���Ҫ��������������
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 19;
	cout << "Sheep::m_Age = " <<st.Sheep::m_Age<< endl;
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout<<st.m_Age<<endl;

	system("pause");
	return 0;
}