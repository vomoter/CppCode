#include<iostream>
using namespace std;

int main1() {

	short num1 = 10;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;

	cout << "shortռ�ÿռ��ڴ�Ϊ:" << sizeof(num1) << endl;
	cout << "intռ�ÿռ��ڴ�Ϊ:" << sizeof(num2) << endl;
	cout << "longtռ�ÿռ��ڴ�Ϊ:" << sizeof(num3) << endl;
	cout << "long longռ�ÿռ��ڴ�Ϊ:" << sizeof(num4) << endl;

	system("pause");
	return 0;
}