#pragma once
#include"worker.h"


class Employee :public Worker
{
public:

	//有参构造函数
	Employee(int id, string name, int deptid);
	
	//显示个人信息
	void showInfo();

	//获取岗位名称
	string getDeptName();


};