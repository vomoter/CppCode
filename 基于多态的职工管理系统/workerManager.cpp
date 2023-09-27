#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

#define FILENAME "empFile.txt"

//初始化属性
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())	//文件不存在
	{
		
		this->m_Num = 0;			//初始化属性
		this->m_Array = NULL;	   //初始化数组指针
		this->m_FileIsEmpty = true;//初始化文件是否为空
		ifs.close();
		return;
	}
	
	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())	//文件为空
	{
		this->m_Num = 0;
		this->m_Array = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3文件存在，并且记录数据
	int num = this->getEmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_Num = num;

	//开辟空间
	this->m_Array = new Worker *[this->m_Num];
	//将读取文件的数据，存在数组中
	this->initEmp();

/*	for (int i = 0; i < this->m_Num; i++)
	{
		cout << "职工编号：" << this->m_Array[i]->m_ID;
		cout << " 职工姓名为：" << this->m_Array[i]->m_Name;
		cout << " 部门编号为：" << this->m_Array[i]->m_DeptID << endl;
	}*/

}

//显示菜单
void WorkerManager::showMenu()
{
	cout << "*************************************************" << endl;
	cout << "***************欢迎使用职工管理系统**************\n" << endl;
	cout << "***************0.退出管理系统********************\n" << endl;
	cout << "***************1.添加职工信息********************\n" << endl;
	cout << "***************2.显示职工信息********************\n" << endl;
	cout << "***************3.删除离职职工********************\n" << endl;
	cout << "***************4.修改职工信息********************\n" << endl;
	cout << "***************5.查找职工信息********************\n" << endl;
	cout << "***************6.按照编号排序********************\n" << endl;
	cout << "***************7.清空所有文档********************\n" << endl;
	cout << "" << endl;

}

//添加职工
void WorkerManager::addEmp()
{
	
	cout << "请输入添加职工的数量：" << endl;
	int num = 0;
	cin >> num;
	if (num > 0)
	{
		
		//计算添加新空间大小
		int newSize = this->m_Num + num;
		Worker** newSpace = new Worker* [newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_Array != NULL)
		{
			for (int i = 0; i < this->m_Num; i++)
			{
				newSpace[i] = this->m_Array[i];
			}
		}

		//批量添加新数量
		for ( int i = 0; i < num; i++)
		{
			int id;		 //职工编号
			string name; //职工姓名
			int select;	 //部门选择

			cout << "请输入" << i + 1 << "个新职工编号：";
			cin >> id;
			for (int i = 0; i < this->m_Num; i++)
			{
				if (id == this->m_Array[i]->m_ID)
				{
					cout << "此编号已经存在，请重新输入编号:" << endl;
					cin >> id;
				}
			}
			cout << "请输入" << i + 1 << "个新职工姓名: ";
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> select;

			Worker* worker = NULL;
			switch (select)
			{
			case 1:
				worker = new Employee(id, name, 1);
					break;
			case 2:
				worker = new Manager(id, name, 2);
					break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this-> m_Num + i] = worker;
		}
		//释放原有空间
		delete[] this->m_Array;

		//更改新空间的指向
		this->m_Array = newSpace;

		//更新新的职工人数
		this->m_Num = newSize;

		//更新职工不为空
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" <<num<<"个人信息" << endl;

		//保存数据
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
//	按任意键，清屏返回上级目录
	system("pause");
	system("cls");

}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);	//用输出的方式打开文件  --写文件
	//把每个人的数据写入文件中
	for (int i = 0; i <this->m_Num; i++)
	{
		ofs << this->m_Array[i]->m_ID << " "
			<< this->m_Array[i]->m_Name<< " "
			<< this->m_Array[i]->m_DeptID << endl;
	}
	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;
	int num = 0;

	while (ifs>>id && ifs>>name && ifs>>did)
	{
		num++;
	}
	return num;
}

//初始化员工
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;

		if (did == 1)	//普通职工
		{
			worker = new Employee(id,name,did);
		}
		else if (did == 2)	//经理
		{
			worker = new Manager(id,name,did);
		}
		else
		{
			worker = new Boss(id,name,did);
		}
		this->m_Array[index] = worker;
		index++;
	}
	ifs.close();

}

//显示职工
void WorkerManager::showEmp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i <m_Num;i++)
		{
			//利用多态调用程序接口
			this->m_Array[i]->showInfo();
		}
	}
	//按任意键返回上一级并清屏
	system("pause");
	system("cls");
}

//判断职工编号是否存在,返回在数组的下标，不存在返回-1
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_Num; i++)
	{
		if (this->m_Array[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkerManager::deleteEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工编号：" << endl;
		int id=0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_Num; i++)
			{
				//数据前移
				this->m_Array[i] = this->m_Array[i + 1];
			}
			this->m_Num--;	//更新数据
			this->save();	//数据更新到文件中
		}	
		else
		{
			cout<<"没有查到此信息" << endl;
		}
	}
	//按任意键、清屏
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::modfifyEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入修改的编号" << endl;
		int id;
		cin >> id;

		int result = this->isExist(id);
		if (result != -1)
		{
			delete this->m_Array[result];

			int newid = 0;
			string newname = "";
			int newselect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;

			cout << "请输入新姓名:" << endl;
			cin >> newname;

			cout << "请输入新的岗位：" << endl;
			cin >> newselect;
			Worker* worker = NULL;
			if (newselect == 1)
			{
				worker = new Employee(newid,newname,newselect);
			}
			else if (newselect==2)
			{
				worker = new Manager(newid,newname,newselect);
			}
			else if (newselect==3)
			{
				worker = new Boss(newid,newname,newselect);
			}
			//更新数据 到数组中
			this->m_Array[result] = worker;
			cout << "修改成功" << endl;
			//保存到文件中
			this->save();
		}
		else
		{
			cout << "没有查到此数据" << endl;
		}
	}
	//按任意键、清屏
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout<<"请输入查找的方式" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入要查找的职工编号" << endl;
			int id;
			cin >> id;
			int result = isExist(id);
			if (result != -1)
			{
				cout << "查询成功！" << endl;
				this->m_Array[result]->showInfo();
			}
			else
			{
				cout << "查找失败" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "请输入要查找的职工姓名" << endl;
			string name;
			cin >> name;
			//加入是否查到的标志
			bool flag = false;	//默认没有找到职工
			for (int i = 0; i < m_Num; i++)
			{
				if (this->m_Array[i]->m_Name == name)
				{
					cout << "查询成功！" << endl;
					this->m_Array[i]->showInfo();
					flag = true;
				}
				
			}
			if (flag == false)
			{
				cout << "没有查到此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
	//按任意键、清屏
	system("pause");
	system("cls");
}

//排序职工编号
void WorkerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式:" << endl;
		cout << "1.按照职工号进行升序" << endl;
		cout << "2.按照职工号进行降序" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < m_Num; i++)
		{
			int minOrMax = i;	//声明最小值或者最大值
			for (int j = i + 1; j < m_Num; j++)
			{
				if (select == 1)
				{
					if (this->m_Array[minOrMax]->m_ID > this->m_Array[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_Array[minOrMax]->m_ID < this->m_Array[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}
			//判断开始假设的最大值或者最小值 是不是最大值或者最小值 ，如果不是则交换数据
			if (i != minOrMax)
			{
				Worker* temp = this->m_Array[i];
				this->m_Array[i] = this->m_Array[minOrMax];
				this->m_Array[minOrMax] = temp;
			}	
		}
		cout << "排序成功！结果如下" << endl;
		//this->save() //结果存入文件
		this->showEmp();
	}
}

void WorkerManager::clearFile()
{
	cout << "确定清空吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.退出" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_Array != NULL)
		{
			//删除堆区的每一个职工对象
			for (int i = 0; i < this->m_Num; i++)
			{
				if (this->m_Array != NULL)
				{
					delete this->m_Array[i];
					this->m_Array[i] = NULL;
				}
			}
			delete[] this->m_Array;
			this->m_Array = NULL;
			this->m_Num = 0;
			this->m_FileIsEmpty = true;
		}
	}
	
	system("pause");
	system("cls");

}

//退出系统
void WorkerManager::exitSystem()
{
	cout<<"欢迎下次使用" << endl;
	system("pause");
	exit(0);	//退出程序
}

//析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_Array != NULL)
	{
		for (int i = 0; i < this->m_Num; i++)
		{
			if (this->m_Array != NULL)
			{
				delete this->m_Array[i];
				this->m_Array[i] = NULL;
			}
		}
		delete[] this->m_Array;
		this->m_Array = NULL;
	}
}

