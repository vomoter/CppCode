#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	//1.����ͷ�ļ� fstrream

	//2.����������
	ifstream ifs;

	//3.���ļ�,���ж��ļ��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout<<"�ļ���ʧ��" << endl;
		return 0;
	}

	//4.������
	//һ���Կո�Ϊ�ָ�����
/*	char buff[1024] = {0};
	while (ifs >> buff)
	{
		cout<< buff << endl;
	}*/

	//�������ж�
/*	char buff[1024] = {0};
	while (ifs.getline(buff,sizeof buff))
	{
		cout << buff << endl;
	}*/

	//�������ַ���һ��һ�ж�
/*	string str;
	while (getline(ifs,str))
	{
		cout << str<<endl;
	}*/

	//���ַ�һ��һ����
	char ch;
	while ( (ch=ifs.get()) != EOF)	// end of file
	{
		cout << ch;
	}
	

	//5.�ر��ļ�
	ifs.close();

	system("pause");
	return 0;
}