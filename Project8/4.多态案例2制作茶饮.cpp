#include<iostream>
using namespace std;

/*
	���ö�̬ʵ�֣��ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ
	���ȣ�1.��ˮ 2.���ݿ��� 3.���뱭�� 4�����Ǻ�ţ��
	��Ҷ��1.��ˮ 2.���ݲ�Ҷ 3.���뱭�� 4.������

*/

class AbstractDrinking
{
public:
	
	//��ˮ
	virtual void Boil() = 0;

	//����
	virtual void Brew() = 0;

	//���뱭��
	virtual void PutIntoCup() = 0;

	//��������
	virtual void PutSomething() = 0;

};

class Coffee : public AbstractDrinking
{
public:
	void Boil()
	{
		cout<<"������ˮ" << endl;
	}

	void Brew()
	{
		cout << "���ݿ���" << endl;
	}

	void PutIntoCup()
	{
		cout << "���뱭��" << endl;
	}

	void PutSomething()
	{
		cout << "����һ�鷽��" << endl;
	}
};

class Tea : public AbstractDrinking
{
public:

	void Boil()
	{
		cout << "��Ҷ��ˮ" << endl;
	}

	void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}

	void PutIntoCup()
	{
		cout << "���뱭��" << endl;
	}

	void PutSomething()
	{
		cout << "���������" << endl;
	}

};

//������Ʒ����
void doWork(AbstractDrinking *abs)
{
	abs->Boil();
	abs->Brew();
	abs->PutIntoCup();
	abs->PutSomething();

}
int main4()
{
	//��������
	doWork(new Coffee);	//AbstractDrinking *abs = new Coffee
	cout << endl;
	Tea tea;
	//������Ҷ
	doWork(&tea);
	

	system("pause");
	return 0;
}