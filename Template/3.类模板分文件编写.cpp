#include"person.hpp"

/*
	因为类模板成员函数是在类模板调用后生成的，要使用类模板分文件编写
	第一种解决方法：直接包含源文件
	//#include"person.cpp"
	第二种解决方式，将.h和.cpp中的内容写在一起，然后缀名.hpp

*/
int main3()
{
	Person<string,int> p1("张珊",18);
	p1.displayType();
	p1.displayPerson();

	system("pause");
	return 0;
}