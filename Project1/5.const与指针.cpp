#include<iostream>
using namespace std;
int main5() {
	int a = 10;
	int b = 10;

	//����ָ�룺ָ���ָ�򣨵�ַ�����Ըı䣬��ָ���ָ���ֵ���ܸı�
	const int * p1 = &a;
	cout << p1 << endl;
	p1 = &b;
	cout << p1<< endl;

	//ָ�볣����ָ���ָ�򣨵�ַ�������Ըı䣬��ָ���ָ���ֵ���Ըı� 
	int * const p2 = &a;
	cout <<endl<<*p2 << endl;
	*p2 = 20;
	cout << *p2 << endl;

	//������ָ�룬�����γ�����ָ���ָ�򣨵�ַ�������Ըı䣬ָ���ָ���ֵ�����Ըı� 
	const int * const p3 = &a;
	cout << endl<<p3 << endl;
	cout << *p3 << endl;
	system("pause");
	return 0;
}