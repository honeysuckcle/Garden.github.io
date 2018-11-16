#include<iostream>
#include"Queue.h"

using namespace std;

void main()
{
	Queue<int> a(10);

	for (int i = 0; i < 10; i++)
		a.Add(i);

	cout << a.IsFull() << endl;

	for (int i = 0; i < 10; i++)
		a.Delete();

	cout << a.IsEmpty() << endl;

	system("pause");
	return;
}
