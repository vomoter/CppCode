#pragma once
#include"worker.h"

//������
class Manager : public Worker
{
public:

	//���캯��
	Manager(int id, string name, int deptid);

	//��ʾ������Ϣ
	virtual void showInfo() ;

	//��ȡ��λ����
	virtual string getDeptName();
};