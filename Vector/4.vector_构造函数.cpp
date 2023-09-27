#include<iostream>
#include<vector>
using namespace std;

/*
	����ԭ�ͣ�
	1. vector<T> v;		����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	2. vector(v.begin(), v.end());		//��v.begin(), v.end()�����е�Ԫ�ظ�����
	3. vector(n,size);					//���캯����n��elem����������
	4. vector(const vector &vec);		//�������캯��

*/

//��ӡvector����Ԫ��
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
	vector<int> v1;	//1. vector<T> v;		����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end());	//2. vector(v.begin(), v.end());		
	//��v.begin(), v.end()�����е�Ԫ�ظ�����
	printVector(v1);

	vector<int> v3(10, 100);	//3. vector(n,size);					
	//���캯����n��elem����������
	printVector(v3);

	vector<int> v4(v3);		//4. vector(const vector &vec);		�������캯��
	printVector(v4);

	system("pause");
	return 0;
}