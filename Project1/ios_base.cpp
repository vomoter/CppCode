#include<iostream>
using namespace std;

int main6() {

	double d= 3.1415926;
	float f = 3.2e5f;

	//ios_base::fixed,用正常的计数法来记浮点数（与科学计数法对应）
	//floatfield，表示浮点数保留6位小数
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout<<"double="<<d << endl;
	cout << "float="<<f << endl;

	system("pause");
	return 0;
}