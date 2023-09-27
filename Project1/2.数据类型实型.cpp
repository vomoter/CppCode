#include<iostream>
using namespace std;

int main2() {

	float f1 = 3.14f;
	double d1 = 3.14;

	cout << f1 << endl;
	cout << d1 << endl;

	cout << "float sizeof=" << sizeof(f1) << endl;
	cout << "double sizeof=" << sizeof(d1) << endl;

	//科学计数法
	float f2 = 3e2;//3*10^2
	double d2 = 3e-2;//3*10^-1

	cout << "f2 = " << f2 << endl;
	cout << "d2=" << d2 << endl;



	system("pause");
	return 0;
}