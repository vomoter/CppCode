#include<iostream>
using namespace std;

class MyInteger
{
	//重载函数做友元，可以访问该类的私有成员
	friend ostream& operator<<(ostream& cout, MyInteger m);
private:	
	int m_Num;

public:
	MyInteger()
	{
		m_Num = 0;
	}

	//重载前置++运算符，返回引用为了一直对一个数据进行递增
	MyInteger& operator++()
	{
		++m_Num;		//选进行++运算
		return *this;	//再将自身返回
	}

	//重载后置++运算符，int代表占位参数，可以用于区分前置和后缀递增
	MyInteger operator++(int)
	{
		MyInteger temp = *this;	//先记录当时结果
		m_Num++;				//后递增
		return temp;			//再将记录结果返回
	}
};

//左移运算符重载
ostream &operator<<(ostream &cout, MyInteger m)
{
	cout << "m_Num = " << m.m_Num;
	return cout;
}

int main3()
{
	MyInteger m,n;
	cout <<++ (++m)<< endl;
	
	cout << n++<<endl;
	cout << n<<endl;

	system("pause");
	return 0;
}