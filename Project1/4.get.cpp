#include<iostream>
using namespace std;

int main4() {
	
	cout <<"What year was your house built?"<< endl;
	int year;
	cin >> year;

	//get()并不读取并丢弃换行符，而是将其留在输入队列中，等待下一个调用get()读取
	cin.get();

	cout << "What is its street address?" << endl;
	char address[40];

    //getline()函数每次读取一行，并把Enter键的换行符，转换为空字符'\0'
	cin.getline(address,40);
	//如果没有调用get(),在cin输入读取年份时，换行符留在输入队列中，当cin.getlin()看到换行符时，认为是空行，把其转换'\0'
	//则此时address数组为空字符串，不会输出address

	cout << "Yrar built:" <<year<<endl;
	cout << "Address:"<<address<< endl;
	cout << "Done!" << endl;


	system("pause");
	return 0;
}