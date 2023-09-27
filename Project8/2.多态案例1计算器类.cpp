#include<iostream>
#include<string> 
using namespace std;
/*
	多态好处：
	1.组织结构清晰
	2.可读性强
	3.对于前期和后期扩展以及维护性高
*/
//分别利用普通写法和多态实现计算器

//普通写法
class Calculator
{
public:
	int m_Num1;	//操作数1
	int m_Num2;	//操作数2

	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		/*
			如果想扩展新的功能，需要修改源码
			在真的开发中，提倡开闭原则
			开闭原则：对扩展进行开发。对修改进行关闭
		*/
	}
};

//实现计算器抽象类
class AbstractCalculator
{
public:

	int m_Num1;	//操作数1
	int m_Num2;	//操作数2
	
	virtual int getResult()
	{
		return 0;
	}
};

//加法计算器类
class AddCalculator : public AbstractCalculator
{
public:

	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//减法计算器类
class SubCalculator : public AbstractCalculator
{
public:

	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//乘法计算器类
class MulCalculator : public AbstractCalculator
{
public:

	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

//除法计算器类
class CuCalculator : public AbstractCalculator
{
public :

	int getResult()
	{
		if (m_Num1 == 0 || m_Num2 == 0)
		{
			return 0;
		}
		else
		{
			return m_Num1 / m_Num2;
		}
	}
};

void test1()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

void test2()
{
	//多态使用条件
	//父类指针或者引用指向子类对象

	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout<<abc->m_Num1<<" + "<<abc->m_Num2<<" = "<<abc->getResult() << endl;
	//new对应delete,用完销毁
	delete abc;

	//减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//除法运算
	abc = new CuCalculator;
	abc->m_Num1 = 300;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;




}
int main2()
{
	test2();

	system("pause");
	return 0;
}