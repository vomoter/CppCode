#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"worker.h"
#include"boss.h"
//#include<iostream>


int main()
{
	Worker* worker = NULL;
/*	worker = new Employee(1, "����", 1);
	worker->showInfo();
	//ɾ������
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
	*/

	//ʵ�����������
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();	//��ʾ�˵�
		cout << "���������ѡ��";
		cin >> choice;
		switch (choice)
		{
		case 0:	wm.exitSystem();	//�˳�ϵͳ
			 break;
		case 1:	wm.addEmp();	//���ְ��
			break;
		case 2:	wm.showEmp();	//��ʾְ��
			break;
		case 3:	wm.deleteEmp();	//ɾ��ְ��
			break;
		case 4:	wm.modfifyEmp();	//�޸�ְ��
			break; 
		case 5:	wm.findEmp();	//����ְ��
			break;
		case 6:	wm.sortEmp();	//���ձ������
			break;
		case 7:	wm.clearFile();	//��������ĵ�
			break;
		default:
			system("cls");
		}

	}
	
	system("pause");
	return 0;
}