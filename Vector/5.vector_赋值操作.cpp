#include<iostream>
#include<vector>
using namespace std;

/*
	����ԭ�ͣ�
		1. vector& operator(const vector &vec); //���صȺŲ�����
		2. assign(beg, end);    //��(beg,end)�����е����ݿ�����ֵ������
		3. assign(n, elem);     //��ng��elem������ֵ������
*/


//��ӡvector����Ԫ��
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
	vector<int> v1;	//Ĭ�Ϲ��캯��
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}
	print(v1);

	vector<int> v2;	// 1.vector& operator(const vector &vec); //���صȺŲ�����
	v2 = v1;
	print(v2);

	vector<int> v3;	//2. assign(beg, end);    //��(beg,end)�����е����ݿ�����ֵ������
	v3.assign(v1.begin(), v1.end());
	print(v3);

	vector<int> v4;
	v4.assign(10, 100);
	print(v4);	//	3.assign(n, elem);     //��ng��elem������ֵ������

	system("pause");
	return 0;
}