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
		push_back(element)			β������Ԫ��element
		pop_back()					ɾ�����һ��Ԫ��
		insert(const_iterator pos,element)					������ָ��λ��pos����Ԫ��element
		insert(const_iterator pos,int count, element);		������ָ��λ��pos����count��Ԫ��element
		erase(const_iterator pos);							ɾ��������ָ���Ԫ��
		erase(const_iterator start, const_iterator end);	ɾ����������start��end֮���Ԫ��
		clear();					ɾ������������Ԫ��
	
	
	*/
	vector<int> v;
	for (int i = 1; i <= 10; i++)
	{
		v.push_back(i);
	}
	printElement(v);

	//������ָ��λ��pos����Ԫ��element
	v.insert(v.begin(), 100);
	printElement(v);

	//������ָ��λ��pos����count��Ԫ��element
	v.insert(v.end(), 2, 100);
	printElement(v);

	//ɾ��������ָ���Ԫ��
	v.erase(v.begin());
	printElement(v);

	//������Ԫ��ȫ����ֵ������t
	vector<int> t = v;
	//ɾ����������start��end֮���Ԫ��
	v.erase(v.begin(),v.end());
	printElement(v);
	cout << "capacity: " << v.capacity() << endl;
	cout << "size: " << v.size() << endl<<endl;

	//ɾ������������Ԫ��
	t.clear();
	cout << "capacity: " << v.capacity() << endl;
	cout << "size: " << v.size() << endl;
	system("pause");
	return 0;
}