#include<iostream>
using namespace std;

/*
	利用多态实现，提供抽象类作饮品基类，提供子类制作咖啡和茶叶
	咖啡：1.煮水 2.冲泡咖啡 3.倒入杯中 4。加糖和牛奶
	茶叶：1.煮水 2.冲泡茶叶 3.倒入杯中 4.加柠檬

*/

class AbstractDrinking
{
public:
	
	//煮水
	virtual void Boil() = 0;

	//冲泡
	virtual void Brew() = 0;

	//倒入杯中
	virtual void PutIntoCup() = 0;

	//加入佐料
	virtual void PutSomething() = 0;

};

class Coffee : public AbstractDrinking
{
public:
	void Boil()
	{
		cout<<"咖啡煮水" << endl;
	}

	void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}

	void PutIntoCup()
	{
		cout << "倒入杯中" << endl;
	}

	void PutSomething()
	{
		cout << "加入一块方糖" << endl;
	}
};

class Tea : public AbstractDrinking
{
public:

	void Boil()
	{
		cout << "茶叶煮水" << endl;
	}

	void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}

	void PutIntoCup()
	{
		cout << "倒入杯中" << endl;
	}

	void PutSomething()
	{
		cout << "加入金银花" << endl;
	}

};

//制作饮品函数
void doWork(AbstractDrinking *abs)
{
	abs->Boil();
	abs->Brew();
	abs->PutIntoCup();
	abs->PutSomething();

}
int main4()
{
	//制作咖啡
	doWork(new Coffee);	//AbstractDrinking *abs = new Coffee
	cout << endl;
	Tea tea;
	//制作茶叶
	doWork(&tea);
	

	system("pause");
	return 0;
}