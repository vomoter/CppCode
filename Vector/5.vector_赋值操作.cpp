#include<iostream>
#include<vector>
using namespace std;

/*
	函数原型：
		1. vector& operator(const vector &vec); //重载等号操作符
		2. assign(beg, end);    //将(beg,end)区间中的数据拷贝赋值给本身
		3. assign(n, elem);     //将ng个elem拷贝赋值给本身
*/


//打印vector数组元素
void print(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main5()
{
	vector<int> v1;	//默认构造函数
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}
	print(v1);

	vector<int> v2;	// 1.vector& operator(const vector &vec); //重载等号操作符
	v2 = v1;
	print(v2);

	vector<int> v3;	//2. assign(beg, end);    //将(beg,end)区间中的数据拷贝赋值给本身
	v3.assign(v1.begin(), v1.end());
	print(v3);

	vector<int> v4;
	v4.assign(10, 100);
	print(v4);	//	3.assign(n, elem);     //将ng个elem拷贝赋值给本身

	system("pause");
	return 0;
}