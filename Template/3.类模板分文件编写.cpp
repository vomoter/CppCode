#include"person.hpp"

/*
	��Ϊ��ģ���Ա����������ģ����ú����ɵģ�Ҫʹ����ģ����ļ���д
	��һ�ֽ��������ֱ�Ӱ���Դ�ļ�
	//#include"person.cpp"
	�ڶ��ֽ����ʽ����.h��.cpp�е�����д��һ��Ȼ��׺��.hpp

*/
int main3()
{
	Person<string,int> p1("��ɺ",18);
	p1.displayType();
	p1.displayPerson();

	system("pause");
	return 0;
}