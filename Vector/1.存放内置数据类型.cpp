#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void myPrint(int a)
{
	cout << a << " ";
}
int main1()
{
	vector<int> a;		//创建一个int型的vector容器

	//利用尾插法添加数据
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);

	//通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = a.begin();	//起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = a.end();		//结束迭代器，指向容器最后一个元素的下一个位置

	//第一种方法遍历
	cout << "第一种方法遍历:" << endl;
	while (itBegin!=itEnd)
	{
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << "\n第二种方法遍历:" << endl;
	//第二种方法遍历
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it<< " ";
	}
	
	cout << "\n第三种方法遍历:" << endl;
	for_each(a.begin(), a.end(), myPrint);
	cout << endl;

	system("pause");
	return 0;
}