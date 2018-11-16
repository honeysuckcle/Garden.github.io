#include<iostream>
#include<list>
using namespace std;

int count(list<int> chain,int n)
{
	list<int>::iterator itFirst = chain.begin();
	list<int>::iterator itSecond = chain.begin();
	for (int i = 0; i < 5; i++)
		itSecond++;
	int result=0;
	for (int i = 0; i < n - 5; i++)
	{
		result += (*itFirst++) * (*itSecond++);
	}
	return result;
}

int main() {
	list<int> chain;
	int x , n;
	cout << "input n:\n";
	cin >> n;
	cout << "input X1 X2 ... Xn:\n";
	for (int i = 0; i < n; i++) {
		x = cin.get();
		chain.push_back(x);
	}
	cout << "result:" << count(chain, n) << endl;
	system("pause");
	return 1;
}