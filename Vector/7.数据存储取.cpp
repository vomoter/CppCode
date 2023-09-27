#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& v)
{
	for (int i=0;i<v.size();i++)
	{
		//	����������ָ������
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	/*
		at(int index);		��������index��ָ������
		operator[];			����������ָ������
		front();			���������е�һ������Ԫ��
		back();				�������������һ������Ԫ��
	*/
	vector<int> v;
	for (int i = 1; i <= 10; i++)
	{
		v.push_back(i);
	}
	display(v);

	//��������index��ָ������
	auto a = v.at(0);
	cout << "index 0: " << a << endl;

	//���������е�һ������Ԫ��
	auto b = v.front();
	cout << "v.front(): " << b << endl;

	//�������������һ������Ԫ��
	auto c = v.back();
	cout << "v.back() " << c << endl;
	cout << "typedef:"<< typeid(c).name() << endl;
	


	system("pause");
	return 0;
}