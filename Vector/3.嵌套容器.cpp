#include<iostream>
#include<vector>
using namespace std;

int main3()
{
	vector<vector<int>> v;

	//����С����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	//��С�������Ԫ��
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i+1);
		v2.push_back(i+2);
		v3.push_back(i+3);
		v4.push_back(i+4);
	}

	//��С���������������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//������������Ԫ��
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator itm = (*it).begin(); itm != (*it).end(); itm++)
		{
			cout << *itm << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}