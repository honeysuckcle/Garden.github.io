#include<iostream>
using namespace std;

class Array
{
public:
	Array();
	~Array();
    int compare(Array &b) const;//比较大小
private:
	
	int size;//数组大小
	int *arr;//数组
};

Array::Array()
{
	cout << "please input the size:";
	cin >> size;
	arr = new int[size];
	cout << "please input the array:";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << "input sucess!\n";
}

Array::~Array()
{
	delete[]arr;
}

int Array::compare(Array &b) const
{
	if (size < b.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == b.arr[i]) continue;
			if (arr[i] < b.arr[i]) return -1;
			if (arr[i] > b.arr[i]) return 1;
		}
		return -1;
	}
	else
	{
		for (int i = 0; i < b.size; i++)
		{
			if (arr[i] == b.arr[i]) continue;
			if (arr[i] < b.arr[i]) return -1;
			if (arr[i] > b.arr[i]) return 1;
		}
	}
	return 0;
}

void main()
{
	cout << "input A:\n";
	Array a;
	cout << "input B:\n";
	Array b;
	switch (a.compare(b))
	{
	case -1:
		cout << "A<B\n";
	case 0:
		cout << "A=B\n";
	case 1:
		cout << "A>B\n";
	}
	system("pause");
}