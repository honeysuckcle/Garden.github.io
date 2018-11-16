#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int binarySearch(int *a,const int x,const int left,const int right)
{
	if (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < a[middle])
			return binarySearch(a, x, left, middle - 1);
		if (x > a[middle])
			return binarySearch(a, x, middle + 1, right);
		if (x == a[middle])
			return middle;
	}
	return -1;
}

void main()
{
	int a[101];
	double time[101];
	clock_t start, stop;
	double runTime, totalTime;
	for (int i = 0; i <= 100; i++)
	{
		a[i] = i;
	}
	cout << "n \t averive runtime \n";
	for (int j = 1; j <= 100; j++)
	{
		start = clock();
		for (int k = 0; k < j; k++)
		{
			int t = binarySearch(a, k, 0, j);
			cout << t<<" ";
		}
		cout << endl;
		stop = clock();
		totalTime = (double)(stop - start) / clock_t(1);
		runTime = totalTime / (double)j;
		time[j] = runTime;
	}
	for (int i = 1; i <= 100; i++)
		cout << time[i] << endl;
	system("pause");
}