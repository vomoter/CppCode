#include<iostream>
#include<string>
using namespace std;

//��̬��ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ���������������
//�����ʽ���������е�����������Ϊ���������ߴ�������
/*
	�鹹�ʹ����������ԣ�
	1.���Խ������ָ���ͷ��������
	2.����Ҫ����ĺ���ʵ��

	�������ʹ��鹹����
	����Ǵ����������������ڳ����࣬�޷�ʵ��������

*/

//ˮ����
class Fruit
{
public:
	Fruit()
	{
		cout << "Fruit��Ĺ��캯������" << endl;
	}

	//�������������Խ�� ����ָ���ͷ��������ʱ���ɾ�������
/*	virtual ~Fruit()
	{
		cout << "Friuit�����������������" << endl;
	}*/

	//����������������������ʵ��
	//���˴��������������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Fruit() = 0;

	virtual void Taste() = 0;
};

Fruit::~Fruit()
{
	cout << "Friuit��Ĵ���������������" << endl;
}

//ƻ����
class Apple : public Fruit
{
public:
	string *name;

	Apple(string name)
	{
		cout << "Apple��Ĺ��캯������" << endl;
		this->name = new string(name);
	}

	~Apple()
	{
		cout << "Apple���������������" << endl;
		if (name != NULL)
		{
			delete name;
			name = NULL;
		}
	}
	void Taste()
	{
		cout <<*name<< "ƻ��ζ���ü���" << endl;
	}
};

void test01()
{
	Fruit * fruit = new Apple("�츻ʿ");
	fruit->Taste();
	delete fruit;
}
int main5()
{
	test01();
	/*
		�ܽ᣺
		1.�������������������������ͨ������ָ���ͷ��������
		2.���������û�ж������ݣ����Բ�дΪ��������������
		3.ӵ�д��鹹��������Ҳ���ڳ�����
	
	*/
	system("pause");
	return 0;
}