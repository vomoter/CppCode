#include"people.h"

void Menu() 
{
	cout << "====== 结构体数组通讯录管理系统 ======" << endl;
	cout << "\t1.添加联系人" << endl;
	cout << "\t2.显示联系人" << endl;
	cout << "\t3.删除联系人" << endl;
	cout << "\t4.查找联系人" << endl;
	cout << "\t5.修改联系人" << endl;
	cout << "\t6.清空联系人" << endl;
	cout << "\t0.退出通讯录" << endl;
	cout << "请输入选择：";
}

//添加联系人
void AddPeople(C* c)
{
	if (c->len == MAXSIZE)
	{
		return;
	}
	else 
	{
		string name;
		int sex;
		int age;
		string number;
		string address;
		cout << "请输入姓名：" << endl;
		cin>>name;
		c->p[c->len].name = name;

		while (true)
		{
			cout << "请输入性别(男为1，女为0)：" << endl;
			cin >> sex;
			if (sex == 1 || sex == 0) {
				c->p[c->len].sex = sex;
				break;
			}
		}
		
		while (true)
		{
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age >=0 && age<=120) {
				c->p[c->len].age = age;
				break;
			}
			
		}

		while (true)
		{
			cout << "请输入手机号码：" << endl;
			cin >> number;
			if (number.length() == 11) {
				c->p[c->len].number = number;
				break;
			}
		}

		cout << "请输入地址：" << endl;
		cin >>address;
		c->p[c->len].address = address;
		
	}
	c->len += 1;


}

//打印通讯录
void DispalyPeople(C* c) 
{

	for (int i = 0; i < c->len; i++)
	{
		int temp=c->p[i].sex;
		string sex;
		if (temp == 1) sex = "男";
		else sex = "女";
		cout <<c->p[i].name<<"\t" << sex <<"\t" 
			<<c->p[i].age <<"\t" << c->p[i].number << "\t" << c->p[i].address << endl;
	}
}

//联系人姓名索引
int IndexOfName(C* c,string name) {

	for (int i = 0; i < c->len; i++)
	{
		if (c->p[i].name == name) 
		{
			return i;
			break;
		}
	}
	return -1;

}

//删除联系人
void DeletePeople(C* c) {
	string name;
	cout << "请输入要删除通讯录人的姓名:" << endl;
	cin >> name;
	if (IndexOfName(c, name) == -1)
	{
		cout << "没有查询到信息！" << endl;
	}
	else 
	{
		int index = IndexOfName(c, name);
		for (int i = index; i < c->len; i++)
		{
			c->p[i] = c->p[i + 1];
			c->len -= 1;
		}
	}
}

//查找联系人
void FindPeople(C* c)
{
	string name;
	cout << "请输入要查询的姓名:" << endl;
	cin>>name;

	if (IndexOfName(c, name) == -1) 
	{
		cout << "没有查询到信息！" << endl;
	}
	else
	{
		int i = IndexOfName(c, name);
		int temp = c->p[i].sex;
		string sex;
		if (temp == 1) sex = "男";
		else sex = "女";
		cout << "姓名:" << c->p[i].name << "  性别:" << sex << "  年龄:"
			<< c->p[i].age << "  手机号码:" << c->p[i].number << "  地址:" << c->p[i].address << endl;
	}
}

//修改联系人
void AlterPeople(C* c) {
	string name;
	cout << "请输入要修改通讯录人的姓名:" << endl;
	cin >> name;
	if (IndexOfName(c, name) == -1)
	{
		cout << "没有查询到信息！" << endl;
	}
	else
	{
		int n = IndexOfName(c, name);
		string newname;
		int sex;
		int age;
		string number;
		string address;
		cout << "请输入姓名：" << endl;
		cin >> newname;
		c->p[n].name = newname;

		while (true)
		{
			cout << "请输入性别(男为1，女为0)：" << endl;
			cin >> sex;
			if (sex == 1 || sex == 0) {
				c->p[n].sex = sex;
				break;
			}
		}

		while (true)
		{
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age >= 0 && age <= 120) {
				c->p[n].age = age;
				break;
			}

		}

		while (true)
		{
			cout << "请输入手机号码：" << endl;
			cin >> number;
			if (number.length() == 11) {
				c->p[n].number = number;
				break;
			}
		}

		cout << "请输入地址：" << endl;
		cin >> address;
		c->p[n].address = address;

	}
	
}

//清空通讯录
void ClearInfo(C* c) {

	c->len = 0;
	cout << "通讯录已经清空!" << endl;
}

int main() {
	struct Contact C;
	C.len = 0;
	Menu();
	bool b = true;
	int choice;
	while (b)
	{
		cin >> choice;
		switch (choice)
		{
		case addPeople:AddPeople(&C); break;
		case dispalyPeople:cout << "姓名" << "\t性别"  << " \t年龄"<< "\t手机号码"<< "\t地址" << endl;
			DispalyPeople(&C); break;
		case deletePeople:DeletePeople(&C); break;
		case findPeople:FindPeople(&C);break;
		case alterPeople:AlterPeople(&C); break;
		case clearInfo:ClearInfo(&C); break;
		case EXIT:b = false;
			cout << "退出" << endl;
			exit(0);
			break;

		default:cout << "输入不合理" << endl;
			break;
		}
		system("pause");
		system("cls");
		Menu();
	}
	return 0;
}