#include<iostream>
using namespace std;

int main6() {

	double d= 3.1415926;
	float f = 3.2e5f;

	//ios_base::fixed,�������ļ��������Ǹ����������ѧ��������Ӧ��
	//floatfield����ʾ����������6λС��
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout<<"double="<<d << endl;
	cout << "float="<<f << endl;

	system("pause");
	return 0;
}