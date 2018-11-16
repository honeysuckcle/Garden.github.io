#include<iostream>
using namespace std;

int n;

void powerset(char *array, bool* select , int i)
{
	if (i == n)
	{
		cout << " (";
		for (int k = 0; k < n; k++)
		{
			if (select[k] == true)
				cout <<array[k];
		}
		cout<<") ";

	}
	else
	{
		select[i] = true;
		powerset(array, select, i + 1);
		select[i] = false;
		powerset(array, select, i + 1);
	}
}

void main()
{
	bool *s;
	cout << "please input n\n";
	cin >> n;
	char *array = new char[n];
	s = new bool[n];
	cout << "please input S\n";
	for (int i = 0; i < n; i++)
		cin >> array[i];
	powerset(array, s, 0);
	delete[]array;
	delete[]s;

	cin >> n;
}