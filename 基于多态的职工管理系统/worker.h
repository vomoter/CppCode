#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���������
class Worker
{
public:
	
	int m_ID;		//ְ�����
	string m_Name;	//ְ������
	int m_DeptID;	//���ű��

	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;

};