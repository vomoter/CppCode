#include<iostream>
#include<fstream>
using namespace std;

/*
	文件打开方式：
	ios::in			为读文件而打开文件
	ios::out		为写文件而打开文件
	ios::ate		初始位置：文件尾
	ios::app		追加方式写文件
	ios::turnc		如果文件存在先删除，再创建
	ios::binary		二进制方式

	文件打开方式可以配合使用，利用管道符
	用二进制方式写文件： ios::binary | ios::out
*/

int main1()
{
	//1.创建头文件 fstrream
	
	//2.创建流对象
	ofstream ofs;

	//3.指定打开反式
	ofs.open("test.txt",ios::out);

	//4.写内容
	ofs << "Just something like this" << endl;
	ofs<<"Hello world!" << endl;

	//5.关闭文件
	ofs.close();

	system("pause");
	return 0;
}