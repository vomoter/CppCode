#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

#define FILENAME "empFile.txt"

//��ʼ������
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())	//�ļ�������
	{
		
		this->m_Num = 0;			//��ʼ������
		this->m_Array = NULL;	   //��ʼ������ָ��
		this->m_FileIsEmpty = true;//��ʼ���ļ��Ƿ�Ϊ��
		ifs.close();
		return;
	}
	
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())	//�ļ�Ϊ��
	{
		this->m_Num = 0;
		this->m_Array = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3�ļ����ڣ����Ҽ�¼����
	int num = this->getEmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_Num = num;

	//���ٿռ�
	this->m_Array = new Worker *[this->m_Num];
	//����ȡ�ļ������ݣ�����������
	this->initEmp();

/*	for (int i = 0; i < this->m_Num; i++)
	{
		cout << "ְ����ţ�" << this->m_Array[i]->m_ID;
		cout << " ְ������Ϊ��" << this->m_Array[i]->m_Name;
		cout << " ���ű��Ϊ��" << this->m_Array[i]->m_DeptID << endl;
	}*/

}

//��ʾ�˵�
void WorkerManager::showMenu()
{
	cout << "*************************************************" << endl;
	cout << "***************��ӭʹ��ְ������ϵͳ**************\n" << endl;
	cout << "***************0.�˳�����ϵͳ********************\n" << endl;
	cout << "***************1.���ְ����Ϣ********************\n" << endl;
	cout << "***************2.��ʾְ����Ϣ********************\n" << endl;
	cout << "***************3.ɾ����ְְ��********************\n" << endl;
	cout << "***************4.�޸�ְ����Ϣ********************\n" << endl;
	cout << "***************5.����ְ����Ϣ********************\n" << endl;
	cout << "***************6.���ձ������********************\n" << endl;
	cout << "***************7.��������ĵ�********************\n" << endl;
	cout << "" << endl;

}

//���ְ��
void WorkerManager::addEmp()
{
	
	cout << "���������ְ����������" << endl;
	int num = 0;
	cin >> num;
	if (num > 0)
	{
		
		//��������¿ռ��С
		int newSize = this->m_Num + num;
		Worker** newSpace = new Worker* [newSize];

		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_Array != NULL)
		{
			for (int i = 0; i < this->m_Num; i++)
			{
				newSpace[i] = this->m_Array[i];
			}
		}

		//�������������
		for ( int i = 0; i < num; i++)
		{
			int id;		 //ְ�����
			string name; //ְ������
			int select;	 //����ѡ��

			cout << "������" << i + 1 << "����ְ����ţ�";
			cin >> id;
			for (int i = 0; i < this->m_Num; i++)
			{
				if (id == this->m_Array[i]->m_ID)
				{
					cout << "�˱���Ѿ����ڣ�������������:" << endl;
					cin >> id;
				}
			}
			cout << "������" << i + 1 << "����ְ������: ";
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> select;

			Worker* worker = NULL;
			switch (select)
			{
			case 1:
				worker = new Employee(id, name, 1);
					break;
			case 2:
				worker = new Manager(id, name, 2);
					break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this-> m_Num + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_Array;

		//�����¿ռ��ָ��
		this->m_Array = newSpace;

		//�����µ�ְ������
		this->m_Num = newSize;

		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" <<num<<"������Ϣ" << endl;

		//��������
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}
//	������������������ϼ�Ŀ¼
	system("pause");
	system("cls");

}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);	//������ķ�ʽ���ļ�  --д�ļ�
	//��ÿ���˵�����д���ļ���
	for (int i = 0; i <this->m_Num; i++)
	{
		ofs << this->m_Array[i]->m_ID << " "
			<< this->m_Array[i]->m_Name<< " "
			<< this->m_Array[i]->m_DeptID << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;
	int num = 0;

	while (ifs>>id && ifs>>name && ifs>>did)
	{
		num++;
	}
	return num;
}

//��ʼ��Ա��
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;

		if (did == 1)	//��ְͨ��
		{
			worker = new Employee(id,name,did);
		}
		else if (did == 2)	//����
		{
			worker = new Manager(id,name,did);
		}
		else
		{
			worker = new Boss(id,name,did);
		}
		this->m_Array[index] = worker;
		index++;
	}
	ifs.close();

}

//��ʾְ��
void WorkerManager::showEmp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i <m_Num;i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_Array[i]->showInfo();
		}
	}
	//�������������һ��������
	system("pause");
	system("cls");
}

//�ж�ְ������Ƿ����,������������±꣬�����ڷ���-1
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_Num; i++)
	{
		if (this->m_Array[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ��
void WorkerManager::deleteEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id=0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_Num; i++)
			{
				//����ǰ��
				this->m_Array[i] = this->m_Array[i + 1];
			}
			this->m_Num--;	//��������
			this->save();	//���ݸ��µ��ļ���
		}	
		else
		{
			cout<<"û�в鵽����Ϣ" << endl;
		}
	}
	//�������������
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::modfifyEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸ĵı��" << endl;
		int id;
		cin >> id;

		int result = this->isExist(id);
		if (result != -1)
		{
			delete this->m_Array[result];

			int newid = 0;
			string newname = "";
			int newselect = 0;

			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newid;

			cout << "������������:" << endl;
			cin >> newname;

			cout << "�������µĸ�λ��" << endl;
			cin >> newselect;
			Worker* worker = NULL;
			if (newselect == 1)
			{
				worker = new Employee(newid,newname,newselect);
			}
			else if (newselect==2)
			{
				worker = new Manager(newid,newname,newselect);
			}
			else if (newselect==3)
			{
				worker = new Boss(newid,newname,newselect);
			}
			//�������� ��������
			this->m_Array[result] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "û�в鵽������" << endl;
		}
	}
	//�������������
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout<<"��������ҵķ�ʽ" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "������Ҫ���ҵ�ְ�����" << endl;
			int id;
			cin >> id;
			int result = isExist(id);
			if (result != -1)
			{
				cout << "��ѯ�ɹ���" << endl;
				this->m_Array[result]->showInfo();
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "������Ҫ���ҵ�ְ������" << endl;
			string name;
			cin >> name;
			//�����Ƿ�鵽�ı�־
			bool flag = false;	//Ĭ��û���ҵ�ְ��
			for (int i = 0; i < m_Num; i++)
			{
				if (this->m_Array[i]->m_Name == name)
				{
					cout << "��ѯ�ɹ���" << endl;
					this->m_Array[i]->showInfo();
					flag = true;
				}
				
			}
			if (flag == false)
			{
				cout << "û�в鵽����" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
	}
	//�������������
	system("pause");
	system("cls");
}

//����ְ�����
void WorkerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ:" << endl;
		cout << "1.����ְ���Ž�������" << endl;
		cout << "2.����ְ���Ž��н���" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < m_Num; i++)
		{
			int minOrMax = i;	//������Сֵ�������ֵ
			for (int j = i + 1; j < m_Num; j++)
			{
				if (select == 1)
				{
					if (this->m_Array[minOrMax]->m_ID > this->m_Array[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_Array[minOrMax]->m_ID < this->m_Array[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}
			//�жϿ�ʼ��������ֵ������Сֵ �ǲ������ֵ������Сֵ ����������򽻻�����
			if (i != minOrMax)
			{
				Worker* temp = this->m_Array[i];
				this->m_Array[i] = this->m_Array[minOrMax];
				this->m_Array[minOrMax] = temp;
			}	
		}
		cout << "����ɹ����������" << endl;
		//this->save() //��������ļ�
		this->showEmp();
	}
}

void WorkerManager::clearFile()
{
	cout << "ȷ�������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.�˳�" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_Array != NULL)
		{
			//ɾ��������ÿһ��ְ������
			for (int i = 0; i < this->m_Num; i++)
			{
				if (this->m_Array != NULL)
				{
					delete this->m_Array[i];
					this->m_Array[i] = NULL;
				}
			}
			delete[] this->m_Array;
			this->m_Array = NULL;
			this->m_Num = 0;
			this->m_FileIsEmpty = true;
		}
	}
	
	system("pause");
	system("cls");

}

//�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout<<"��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);	//�˳�����
}

//��������
WorkerManager::~WorkerManager()
{
	if (this->m_Array != NULL)
	{
		for (int i = 0; i < this->m_Num; i++)
		{
			if (this->m_Array != NULL)
			{
				delete this->m_Array[i];
				this->m_Array[i] = NULL;
			}
		}
		delete[] this->m_Array;
		this->m_Array = NULL;
	}
}

