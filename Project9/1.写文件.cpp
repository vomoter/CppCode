#include<iostream>
#include<fstream>
using namespace std;

/*
	�ļ��򿪷�ʽ��
	ios::in			Ϊ���ļ������ļ�
	ios::out		Ϊд�ļ������ļ�
	ios::ate		��ʼλ�ã��ļ�β
	ios::app		׷�ӷ�ʽд�ļ�
	ios::turnc		����ļ�������ɾ�����ٴ���
	ios::binary		�����Ʒ�ʽ

	�ļ��򿪷�ʽ�������ʹ�ã����ùܵ���
	�ö����Ʒ�ʽд�ļ��� ios::binary | ios::out
*/

int main1()
{
	//1.����ͷ�ļ� fstrream
	
	//2.����������
	ofstream ofs;

	//3.ָ���򿪷�ʽ
	ofs.open("test.txt",ios::out);

	//4.д����
	ofs << "Just something like this" << endl;
	ofs<<"Hello world!" << endl;

	//5.�ر��ļ�
	ofs.close();

	system("pause");
	return 0;
}