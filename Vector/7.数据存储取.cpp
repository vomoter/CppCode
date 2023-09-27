#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& v)
{
	for (int i=0;i<v.size();i++)
	{
		//	返回索引所指的数据
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	/*
		at(int index);		返回索引index所指的数据
		operator[];			返回索引所指的数据
		front();			返回容器中第一个数据元素
		back();				返回容器中最后一个数据元素
	*/
	vector<int> v;
	for (int i = 1; i <= 10; i++)
	{
		v.push_back(i);
	}
	display(v);

	//返回索引index所指的数据
	auto a = v.at(0);
	cout << "index 0: " << a << endl;

	//返回容器中第一个数据元素
	auto b = v.front();
	cout << "v.front(): " << b << endl;

	//返回容器中最后一个数据元素
	auto c = v.back();
	cout << "v.back() " << c << endl;
	cout << "typedef:"<< typeid(c).name() << endl;
	


	system("pause");
	return 0;
}