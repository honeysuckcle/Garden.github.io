#include<iostream>
using namespace std;

char a[10];
char op[4] = { 'a','b','c','d' };
int b[4]={0};
int count = 0;

void re(int i,int n)
{
	char ch = 'a';
	if (i < n)
	{
		for (int j=0;j<n;j++)
		{
			if (b[j]== 0)
			{
				a[i] = char(j + ch);
				b[j]= 1;
				re(i + 1, n);
				b[j] = 0;
			}
		}
	}
	if (i == n)
	{
		::count++;
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
		}
		cout << '\t';
		if (::count % 6 == 0)
			cout << endl;
		return;
	}
}

void main()
{
	re(0, 4);
	cin.get();
}