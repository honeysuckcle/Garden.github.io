#include<iostream>
#include<list>

using namespace std;

int main()
{
	int array[7] = {};
	list<int> mylist;
	//list<int>::iterator myit;

	cout << "�����ʼֵ��";
	for (int i = 0; i < 7; i++)
	{
		cout << array[i]<<' ';
		mylist.push_back(i);//˳����list��ֵ
	}
	cout << endl;

	//myit = mylist.begin();
	copy(mylist.begin(), mylist.end(),array);
	cout << "���ƺ�����飺";
	for (int i = 0; i < 7; i++)
	{
		cout << array[i] << ' ';
	}
	cin.get();

	return 1;
}