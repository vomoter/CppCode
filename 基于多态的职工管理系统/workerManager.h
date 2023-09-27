#pragma once	//��ֹͷ�ļ��ظ�����
#include"worker.h"
#include<iostream>
using namespace std;

class WorkerManager
{
public:
	
	int m_Num;				 //��¼ְ������
	 Worker** m_Array;		//ְ������ָ��
	 bool m_FileIsEmpty;	//�ж��ļ��Ƿ�Ϊ�� 

	//���캯��
	WorkerManager();
	
	//��ʾ�˵�
	void showMenu();

	//���ְ��
	void addEmp();

	//�����ļ�
	void save();

	//ͳ���ļ�������
	int getEmpNum();

	//��ʼ��Ա��
	void initEmp();

	//��ʾְ��
	void showEmp();

	//�ж�ְ������Ƿ����,������������±꣬�����ڷ���-1
	int isExist(int id);

	//ɾ��ְ��
	void deleteEmp();

	//�޸�ְ��
	void modfifyEmp();

	//����ְ��
	void findEmp();

	//����ְ�����
	void sortEmp();

	//����ļ�
	void clearFile();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~WorkerManager();
	

};
