#pragma once
#include"worker.h"


class Employee :public Worker
{
public:

	//�вι��캯��
	Employee(int id, string name, int deptid);
	
	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string getDeptName();


};