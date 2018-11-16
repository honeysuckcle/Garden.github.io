#include <iostream>
#include <cmath>
#include "Polynomial.h"

using namespace std;

int Polynomial::free = 0;

int main()
{
	double x = 0;
	int as = 0;
	int bs = 0;

	cout << "Enter a 的 size : ";
	cin >> as;
	cout << "Enter b 的 size : ";
	cin >> bs;
	//初始化多项式a,b
	Polynomial a(as);
	Polynomial b(bs);

	//增加项到 a,b
	cout << "多项式 A" << endl;
	a.addTerm();
	cout << "多项式 B" << endl;
	b.addTerm();

	cout << "Enter x :";
	cin >> x;

	//给定x,计算多项式 a 的值
	cout<<"Value of polynomial a  : "<<a.Evaluate(x)<<endl;
	cout<<"Value of polynomial b  : " << b.Evaluate(x) << endl;

	Polynomial c = a.Add(b);
	cout << "Value of polynomial a+b  : " << c.Evaluate(x) << endl;

	Polynomial d = a.Multiply(b);
	cout << "Value of polynomial a*b  : " << d.Evaluate(x) << endl;

	system("pause");
	return 0;
}