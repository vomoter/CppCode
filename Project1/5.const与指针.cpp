#include<iostream>
using namespace std;
int main5() {
	int a = 10;
	int b = 10;

	//常量指针：指针的指向（地址）可以改变，但指针的指向的值不能改变
	const int * p1 = &a;
	cout << p1 << endl;
	p1 = &b;
	cout << p1<< endl;

	//指针常量：指针的指向（地址）不可以改变，但指针的指向的值可以改变 
	int * const p2 = &a;
	cout <<endl<<*p2 << endl;
	*p2 = 20;
	cout << *p2 << endl;

	//既修饰指针，又修饰常量：指针的指向（地址）不可以改变，指针的指向的值不可以改变 
	const int * const p3 = &a;
	cout << endl<<p3 << endl;
	cout << *p3 << endl;
	system("pause");
	return 0;
}