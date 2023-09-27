#include<iostream>
using namespace std;

int main3() {
	const int ArSize = 20;
	char name[ArSize];
	char sport[ArSize];

	cout << "Enter your name:" << endl;
	cin.getline(name,ArSize);
	cout << "Enter your favorite sport:" << endl;
	cin.getline(sport, ArSize);
	cout << "I like play" <<sport<< endl;
	cout << "My name is:" <<name<< endl;
	system("pause");
	return 0;
}