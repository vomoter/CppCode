#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base�Ĺ��캯������" << endl;
	}

	~Base()
	{
		cout << "Base��������������" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son�Ĺ��캯������" << endl;
	}

	~Son()
	{
		cout << "Son��������������" << endl;
	}

};
void text()
{
	//�ȹ��츸�࣬�ٹ������࣬�����˳���빹���˳���෴
	Son s;
}
int main2()
{
	text();

	system("pause");
	return 0;
}