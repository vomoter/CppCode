#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	//1.创建头文件 fstrream

	//2.创建流对象
	ifstream ifs;

	//3.打开文件,并判断文件是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout<<"文件打开失败" << endl;
		return 0;
	}

	//4.读内容
	//一、以空格为分隔符读
/*	char buff[1024] = {0};
	while (ifs >> buff)
	{
		cout<< buff << endl;
	}*/

	//二、按行读
/*	char buff[1024] = {0};
	while (ifs.getline(buff,sizeof buff))
	{
		cout << buff << endl;
	}*/

	//三、按字符串一行一行读
/*	string str;
	while (getline(ifs,str))
	{
		cout << str<<endl;
	}*/

	//按字符一个一个读
	char ch;
	while ( (ch=ifs.get()) != EOF)	// end of file
	{
		cout << ch;
	}
	

	//5.关闭文件
	ifs.close();

	system("pause");
	return 0;
}