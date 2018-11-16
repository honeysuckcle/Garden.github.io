#include<iostream>
#include<list>

using namespace std;

int main()
{
	int array[7] = {};
	list<int> mylist;
	//list<int>::iterator myit;

	cout << "数组初始值：";
	for (int i = 0; i < 7; i++)
	{
		cout << array[i]<<' ';
		mylist.push_back(i);//顺道给list赋值
	}
	cout << endl;

	//myit = mylist.begin();
	copy(mylist.begin(), mylist.end(),array);
	cout << "复制后的数组：";
	for (int i = 0; i < 7; i++)
	{
		cout << array[i] << ' ';
	}
	cin.get();

	return 1;
}