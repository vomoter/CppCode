#include<iostream>
#include<string>
using namespace std;

class MyPrint
{
public:
	void operator()(string str)
	{
		cout<<str<< endl;
	}
};

class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	MyPrint m;
	//����ʹ�������ǳ������ں������ã���˳�Ϊ�º������ǳ���û�й̶�д��
	//��������ȼ�
	m("Hello World!");
	m.operator()("Hello World!");

	//�������������ʵ�ּӷ�
	MyAdd myadd;
	int result=myadd(10, 20);
	cout<<result<<endl;
	//������������
	cout << MyAdd()(100, 200) << endl;

	system("pause");
	return 0;
}