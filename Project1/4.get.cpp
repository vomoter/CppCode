#include<iostream>
using namespace std;

int main4() {
	
	cout <<"What year was your house built?"<< endl;
	int year;
	cin >> year;

	//get()������ȡ���������з������ǽ���������������У��ȴ���һ������get()��ȡ
	cin.get();

	cout << "What is its street address?" << endl;
	char address[40];

    //getline()����ÿ�ζ�ȡһ�У�����Enter���Ļ��з���ת��Ϊ���ַ�'\0'
	cin.getline(address,40);
	//���û�е���get(),��cin�����ȡ���ʱ�����з�������������У���cin.getlin()�������з�ʱ����Ϊ�ǿ��У�����ת��'\0'
	//���ʱaddress����Ϊ���ַ������������address

	cout << "Yrar built:" <<year<<endl;
	cout << "Address:"<<address<< endl;
	cout << "Done!" << endl;


	system("pause");
	return 0;
}