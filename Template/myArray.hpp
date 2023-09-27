#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
	

private:
	T* pAddress;		//数组
	int m_Capacity;		//容量
	int m_Size;			//数组大小

public:
	//	MyArray();				//无参构造函数
	MyArray(int capacity);	//有参构造函数
	friend ostream& operator<<(ostream& cout, MyArray<T> arr);	//左移运算符重载实现类模板数组元素打印
	MyArray(const MyArray& arr);		//拷贝函数
	MyArray& operator=(const MyArray& arr);		//operator= ,防止浅拷贝问题
	int getCapacity();					//获取当前个数
	int getSize();						//获取数组容量
	T& operator[](int index);		//获取数组下标元素
	void getAll();					//打印全部数组元素
	void addElement(T value);			//尾部增加元素
	void deleteElement();		//尾部删除元素
	~MyArray();				//析构函数
};


template<class T>
MyArray<T>::MyArray(int capacity)	//有参构造函数
{
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new T[this->m_Capacity];
}

template<class T>
MyArray<T>::MyArray(const MyArray& arr)		//拷贝函数
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
	//先判断原来堆区是否有数据，如果有先释放
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
		this->m_Capacity = 0;
		this->m_Size = 0;
	}
	//深拷贝
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
int MyArray<T>::getCapacity()	//获取当前容量
{
	return this->m_Capacity;
}

template<class T>
int MyArray<T>::getSize()	//获取数组大小
{
	return this->m_Size;
}

template<class T>
T& MyArray<T>::operator[](int index)	//获取数组下标元素
{
	return this->pAddress[index];
}

template<class T>
void MyArray<T>::getAll()		//打印全部数组元素
{
	for (int i = 0; i <this->m_Size; i++)
	{
		cout << this->pAddress[i] << " ";
	}
	cout << endl;
}

template<class T>
void MyArray<T>::addElement(T value)	//尾部增加元素
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
 void MyArray<T>::deleteElement()	//尾部删除元素
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
 MyArray<T>::~MyArray()		//析构函数
{
	 if(this->pAddress != NULL)
	 {
		 delete[] this->pAddress;
		 this->pAddress= NULL;
	 }
	
	 cout << "clear all" << endl;
}
