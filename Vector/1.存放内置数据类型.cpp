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
	vector<int> a;		//����һ��int�͵�vector����

	//����β�巨�������
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);

	//ͨ�����������������е�����
	vector<int>::iterator itBegin = a.begin();	//��ʼ��������ָ�������е�һ��Ԫ��
	vector<int>::iterator itEnd = a.end();		//������������ָ���������һ��Ԫ�ص���һ��λ��

	//��һ�ַ�������
	cout << "��һ�ַ�������:" << endl;
	while (itBegin!=itEnd)
	{
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << "\n�ڶ��ַ�������:" << endl;
	//�ڶ��ַ�������
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it<< " ";
	}
	
	cout << "\n�����ַ�������:" << endl;
	for_each(a.begin(), a.end(), myPrint);
	cout << endl;

	system("pause");
	return 0;
}