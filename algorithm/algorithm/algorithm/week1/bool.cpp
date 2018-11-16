#include<iostream>
using namespace std;

void recursion(bool* arr,int i, int n)
{
	if (n+1 == i)
	{
		for (int i = 0; i <= n; i++)
		{

			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		arr[i] = true;
		recursion(arr, i + 1, n);
		arr[i] = false;
		recursion(arr, i + 1, n);
	}
}

void main()
{
	int N = 2;
	while (N)
	{
		cout << "\n Please input n\n";
		cin >> N;
		if (N > 0)
		{
			bool *arr = new bool[N];
			recursion(arr, 0, N - 1);
			delete[]arr;
		}
	}

}