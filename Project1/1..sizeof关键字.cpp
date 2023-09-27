#include<iostream>
using namespace std;

int main1() {

	short num1 = 10;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;

	cout << "short占用空间内存为:" << sizeof(num1) << endl;
	cout << "int占用空间内存为:" << sizeof(num2) << endl;
	cout << "longt占用空间内存为:" << sizeof(num3) << endl;
	cout << "long long占用空间内存为:" << sizeof(num4) << endl;

	system("pause");
	return 0;
}