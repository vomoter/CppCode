#include<iostream>
using namespace std;

/*
	��̬��Ϊ���ࣺ
		��̬��̬���������غ�������������ھ�̬��̬�����ú�����
		��̬��̬����������麯��ʵ������ʱ��̬

	��̬��̬�Ͷ�̬��̬����
		��̬��̬�ĺ�����ַ���  ����׶�ȷ��������ַ
		��̬��̬�ĺ�����ַ���  ���н׶�ȷ��������ַ
*/

//������
class Animal 
{
public :
	virtual void speak()
	{
		cout<<"������˵��" << endl;
	}
};

//è��
class Cat : public Animal
{
public:
	void speak()
	{
		cout<<"Сè��˵��" << endl;
	}
};

class Dog : public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}

};

//ִ��˵���ĺ���
//��ַ��� �ڱ���׶�ȷ��������ַ
//�����ִ��������˵����ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���

/*
	��̬��̬����������
	1.�м̳й�ϵ
	2.������д������麯��

	��̬��̬ʹ�ã�
	�����ָ��������� ִ���������
*/
void doSpeak(Animal& animal)
{
	animal.speak();
}
int main1()
{
	Animal animal;
	Cat cat;
	Dog dog;
	doSpeak(cat);
	doSpeak(dog);
	
	cout<<sizeof(animal)<<endl;

	system("pause");
	return 0;
}