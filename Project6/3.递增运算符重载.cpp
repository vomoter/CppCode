#include<iostream>
using namespace std;

class MyInteger
{
	//���غ�������Ԫ�����Է��ʸ����˽�г�Ա
	friend ostream& operator<<(ostream& cout, MyInteger m);
private:	
	int m_Num;

public:
	MyInteger()
	{
		m_Num = 0;
	}

	//����ǰ��++���������������Ϊ��һֱ��һ�����ݽ��е���
	MyInteger& operator++()
	{
		++m_Num;		//ѡ����++����
		return *this;	//�ٽ�������
	}

	//���غ���++�������int����ռλ������������������ǰ�úͺ�׺����
	MyInteger operator++(int)
	{
		MyInteger temp = *this;	//�ȼ�¼��ʱ���
		m_Num++;				//�����
		return temp;			//�ٽ���¼�������
	}
};

//�������������
ostream &operator<<(ostream &cout, MyInteger m)
{
	cout << "m_Num = " << m.m_Num;
	return cout;
}

int main3()
{
	MyInteger m,n;
	cout <<++ (++m)<< endl;
	
	cout << n++<<endl;
	cout << n<<endl;

	system("pause");
	return 0;
}