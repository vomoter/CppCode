#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"worker.h"
#include"boss.h"
//#include<iostream>


int main()
{
	Worker* worker = NULL;
/*	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	//删除对象
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
	*/

	//实例化管理对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();	//显示菜单
		cout << "请输入你的选择：";
		cin >> choice;
		switch (choice)
		{
		case 0:	wm.exitSystem();	//退出系统
			 break;
		case 1:	wm.addEmp();	//添加职工
			break;
		case 2:	wm.showEmp();	//显示职工
			break;
		case 3:	wm.deleteEmp();	//删除职工
			break;
		case 4:	wm.modfifyEmp();	//修改职工
			break; 
		case 5:	wm.findEmp();	//查找职工
			break;
		case 6:	wm.sortEmp();	//按照编号排序
			break;
		case 7:	wm.clearFile();	//清空所有文档
			break;
		default:
			system("cls");
		}

	}
	
	system("pause");
	return 0;
}