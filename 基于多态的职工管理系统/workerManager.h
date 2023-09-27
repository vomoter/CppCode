#pragma once	//防止头文件重复包含
#include"worker.h"
#include<iostream>
using namespace std;

class WorkerManager
{
public:
	
	int m_Num;				 //记录职工人数
	 Worker** m_Array;		//职工数组指针
	 bool m_FileIsEmpty;	//判断文件是否为空 

	//构造函数
	WorkerManager();
	
	//显示菜单
	void showMenu();

	//添加职工
	void addEmp();

	//保存文件
	void save();

	//统计文件中人数
	int getEmpNum();

	//初始化员工
	void initEmp();

	//显示职工
	void showEmp();

	//判断职工编号是否存在,返回在数组的下标，不存在返回-1
	int isExist(int id);

	//删除职工
	void deleteEmp();

	//修改职工
	void modfifyEmp();

	//查找职工
	void findEmp();

	//排序职工编号
	void sortEmp();

	//清空文件
	void clearFile();

	//退出系统
	void exitSystem();

	//析构函数
	~WorkerManager();
	

};
