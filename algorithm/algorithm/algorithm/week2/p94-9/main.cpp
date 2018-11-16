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

	cout << "Enter a �� size : ";
	cin >> as;
	cout << "Enter b �� size : ";
	cin >> bs;
	//��ʼ������ʽa,b
	Polynomial a(as);
	Polynomial b(bs);

	//����� a,b
	cout << "����ʽ A" << endl;
	a.addTerm();
	cout << "����ʽ B" << endl;
	b.addTerm();

	cout << "Enter x :";
	cin >> x;

	//����x,�������ʽ a ��ֵ
	cout<<"Value of polynomial a  : "<<a.Evaluate(x)<<endl;
	cout<<"Value of polynomial b  : " << b.Evaluate(x) << endl;

	Polynomial c = a.Add(b);
	cout << "Value of polynomial a+b  : " << c.Evaluate(x) << endl;

	Polynomial d = a.Multiply(b);
	cout << "Value of polynomial a*b  : " << d.Evaluate(x) << endl;

	system("pause");
	return 0;
}