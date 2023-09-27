#include<iostream>
#include<string>
using namespace std;

/*
	案例描述：
		电脑主要组成部件为CPU（用于计算），显卡（用于显示），内存条（用于存储）
		将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，列如Intel厂商，Samsung厂商，Nvidia厂商
		创电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
		测试时组装三台不同的电脑进行工作
*/

//CPU抽象类
class CPU
{
public:
	virtual void calculate() = 0;

};

//显卡抽象类
class VideoCard
{
public:
	virtual void display() = 0;

};

//内存抽象类
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
		cout<<"Inter公司制作"<<this->m_name<<" CPU"<< endl;
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
		cout << "Nvidia制作"<<m_name<<"显卡" << endl;
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
		cout << "Samsung制作"<<m_name<<"内存" << endl;
	}
};


//电脑类
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
		m_cpu = cpu;	//CPU的零件指针
		m_videocard = videocard;	//显卡零件指针
		m_memory = memory;	//内存条指针
	}

	~Computer()
	{
		cout<<"析构函数调用" << endl;
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