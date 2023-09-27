#include<iostream>
#include<vector>
using namespace std;

void printElement(vector<int>& v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << *it << " ";
	}
	cout<< endl;

}
int  main6()
{
	/*
		push_back(element)			尾部插入元素element
		pop_back()					删除最后一个元素
		insert(const_iterator pos,element)					迭代器指向位置pos插入元素element
		insert(const_iterator pos,int count, element);		迭代器指定位置pos插入count个元素element
		erase(const_iterator pos);							删除迭代器指向的元素
		erase(const_iterator start, const_iterator end);	删除迭代器重start到end之间的元素
		clear();					删除容器中所有元素
	
	
	*/
	vector<int> v;
	for (int i = 1; i <= 10; i++)
	{
		v.push_back(i);
	}
	printElement(v);

	//迭代器指向位置pos插入元素element
	v.insert(v.begin(), 100);
	printElement(v);

	//迭代器指定位置pos插入count个元素element
	v.insert(v.end(), 2, 100);
	printElement(v);

	//删除迭代器指向的元素
	v.erase(v.begin());
	printElement(v);

	//把容器元素全部赋值给容器t
	vector<int> t = v;
	//删除迭代器重start到end之间的元素
	v.erase(v.begin(),v.end());
	printElement(v);
	cout << "capacity: " << v.capacity() << endl;
	cout << "size: " << v.size() << endl<<endl;

	//删除容器中所有元素
	t.clear();
	cout << "capacity: " << v.capacity() << endl;
	cout << "size: " << v.size() << endl;
	system("pause");
	return 0;
}