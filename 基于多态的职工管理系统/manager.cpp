#include "manager.h"

//�вι��캯��
Manager::Manager(int id, string name, int deptid) 
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deptid;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲����·������Ա��" << endl;

}
//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}
