#include<iostream>
#include<string>
using namespace std;

/*
	����������
		������Ҫ��ɲ���ΪCPU�����ڼ��㣩���Կ���������ʾ�����ڴ��������ڴ洢��
		��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̣�Samsung���̣�Nvidia����
		���������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
		����ʱ��װ��̨��ͬ�ĵ��Խ��й���
*/

//CPU������
class CPU
{
public:
	virtual void calculate() = 0;

};

//�Կ�������
class VideoCard
{
public:
	virtual void display() = 0;

};

//�ڴ������
class Memory
{
public:
	virtual void storage() = 0;
};


class InterCpu : public CPU
{
public:
	string m_name;

	InterCpu(string str)
	{
		this->m_name = str;
	}

	void calculate()
	{
		cout<<"Inter��˾����"<<this->m_name<<" CPU"<< endl;
	}
};

class Nvidia : public VideoCard
{
public:
	string m_name;

	Nvidia(string str)
	{
		this->m_name = str;
	}
	void display()
	{
		cout << "Nvidia����"<<m_name<<"�Կ�" << endl;
	}

};
class Samsung :public Memory
{
public:
	string m_name;

	Samsung(string str)
	{
		this->m_name = str;
	}
	void storage()
	{
		cout << "Samsung����"<<m_name<<"�ڴ�" << endl;
	}
};


//������
class Computer
{
private:
	CPU * m_cpu;
	VideoCard *m_videocard;
	Memory *m_memory;

public:

	Computer() {}

	Computer(CPU* cpu, VideoCard *videocard, Memory *memory)
	{
		m_cpu = cpu;	//CPU�����ָ��
		m_videocard = videocard;	//�Կ����ָ��
		m_memory = memory;	//�ڴ���ָ��
	}

	~Computer()
	{
		cout<<"������������" << endl;
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_videocard != NULL)
		{
			delete m_videocard;
			m_videocard = NULL;
		}
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}
	}

	
	void diyComputer()
	{
		m_cpu->calculate();
		m_videocard->display();
		m_memory->storage();	
	}
};

void Com1()
{
	CPU* cpu;
	VideoCard* videocard;
	Memory* memory;

	cpu = new InterCpu("i9-13900kf");
	videocard = new Nvidia("RTX-4090");
	memory = new Samsung("990pro 2T");
	Computer* computer = new Computer(cpu, videocard, memory);
	computer->diyComputer();
	delete computer;
}
int main()
{
	Com1();
	system("pause");
	return 0;
}