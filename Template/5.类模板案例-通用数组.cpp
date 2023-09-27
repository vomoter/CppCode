#include"myArray.hpp"

void Test()
{
	MyArray<int>p(10);
	int capacity = p.getCapacity();
	int size = p.getSize();
	cout <<"capacity:"<< capacity << endl;
	cout << "size:"<<size << endl;
	cout << &p << endl;
	for (int i = 1; i <= 10; i++)
	{
		p.addElement(i);
	}
	p.getAll();
	cout << "now capacities are:" << p.getCapacity() << endl;
	cout << "now sizes are:" << p.getSize() << endl;
	cout << &p << endl;
}
int main()
{
	Test();

	system("pause");
	return 0;
}