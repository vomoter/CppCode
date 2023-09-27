#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
	

private:
	T* pAddress;		//����
	int m_Capacity;		//����
	int m_Size;			//�����С

public:
	//	MyArray();				//�޲ι��캯��
	MyArray(int capacity);	//�вι��캯��
	friend ostream& operator<<(ostream& cout, MyArray<T> arr);	//�������������ʵ����ģ������Ԫ�ش�ӡ
	MyArray(const MyArray& arr);		//��������
	MyArray& operator=(const MyArray& arr);		//operator= ,��ֹǳ��������
	int getCapacity();					//��ȡ��ǰ����
	int getSize();						//��ȡ��������
	T& operator[](int index);		//��ȡ�����±�Ԫ��
	void getAll();					//��ӡȫ������Ԫ��
	void addElement(T value);			//β������Ԫ��
	void deleteElement();		//β��ɾ��Ԫ��
	~MyArray();				//��������
};


template<class T>
MyArray<T>::MyArray(int capacity)	//�вι��캯��
{
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new T[this->m_Capacity];
}

template<class T>
MyArray<T>::MyArray(const MyArray& arr)		//��������
{
	this->m_Capacity = arr->m_Capacity;
	this->m_Size = arr->m_Size;

	this->pAddress = new T[arr->m_Capacity];
	for (int i = 0; i < this->m_Size; i++)
	{
		this->pAddress[i] = arr->pAddress[i];
	}
}
template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray& arr)
{
	//���ж�ԭ�������Ƿ������ݣ���������ͷ�
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
		this->m_Capacity = 0;
		this->m_Size = 0;
	}
	//���
	this->getCapacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	this->pAddress = new T[arr.m_Capacity];
	for (int i = 0; i < this->m_Size; i++)
	{
		this->pAddress[i] = arr.pAddress[i];
	}
	return *this;
}
template<class T>
int MyArray<T>::getCapacity()	//��ȡ��ǰ����
{
	return this->m_Capacity;
}

template<class T>
int MyArray<T>::getSize()	//��ȡ�����С
{
	return this->m_Size;
}

template<class T>
T& MyArray<T>::operator[](int index)	//��ȡ�����±�Ԫ��
{
	return this->pAddress[index];
}

template<class T>
void MyArray<T>::getAll()		//��ӡȫ������Ԫ��
{
	for (int i = 0; i <this->m_Size; i++)
	{
		cout << this->pAddress[i] << " ";
	}
	cout << endl;
}

template<class T>
void MyArray<T>::addElement(T value)	//β������Ԫ��
{
	if (this->m_Size < this->m_Capacity)
	{
		this->pAddress[this->m_Size]=value;
		this->m_Size++;
	}
	else 
	{
/*		int addCapacity = this->m_Capacity / 2;
		this->m_Capacity += addCapacity;
		T* temp = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			temp[i] = this->pAddress[i];
		}

		delete[] this->pAddress;
		this->pAddress = temp;
		this->m_Size++;*/
		return;
	}
}

template<class T>
 void MyArray<T>::deleteElement()	//β��ɾ��Ԫ��
{
	 if (this->m_Size > 0)
	 {
		 this->pAddress[this->getSize] = NULL;
		 this->m_Size--;
	 }
	 else
	 {
		 return;
	 }
}

 template<class T>
 MyArray<T>::~MyArray()		//��������
{
	 if(this->pAddress != NULL)
	 {
		 delete[] this->pAddress;
		 this->pAddress= NULL;
	 }
	
	 cout << "clear all" << endl;
}
