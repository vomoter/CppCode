#include<iostream>
#include<vector>
using namespace std;

/*
	函数原型：
	1. vector<T> v;		采用模板实现类实现，默认构造函数
	2. vector(v.begin(), v.end());		//将v.begin(), v.end()区间中的元素给本身
	3. vector(n,size);					//构造函数将n个elem拷贝给本身
	4. vector(const vector &vec);		//拷贝构造函数

*/

//打印vector数组元素
void printVector(vector<int> &v)
{
	for (vector<int>::iterator it=v.begin();it!=v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main4()
{
	vector<int> v1;	//1. vector<T> v;		采用模板实现类实现，默认构造函数
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end());	//2. vector(v.begin(), v.end());		
	//将v.begin(), v.end()区间中的元素给本身
	printVector(v1);

	vector<int> v3(10, 100);	//3. vector(n,size);					
	//构造函数将n个elem拷贝给本身
	printVector(v3);

	vector<int> v4(v3);		//4. vector(const vector &vec);		拷贝构造函数
	printVector(v4);

	system("pause");
	return 0;
}