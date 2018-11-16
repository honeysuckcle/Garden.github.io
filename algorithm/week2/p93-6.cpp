#include<iostream>

using namespace std;

class Term
{
public:
	double coef;
	int exp;
	Term(double a, int b) { coef = a; exp = b; }
	Term() { coef = 0; exp = 0; }
	Term(Term& t) { coef = t.coef; exp = t.exp; }
};

class Poly
{
private:
	Term *termArray;
	int size;
public:
	Poly(int s);
	Poly& mutiply(Poly& b);
	void print();
	void input();
	void modify();
	void remove(int);
};

Poly::Poly(int s)
{
	if (s <= 0)
	{
		size = 0;
		termArray = 0;
	}
	else
	{
		termArray = new Term[s];
		size = s;
	}
}

void Poly::input()
{
	double x;
	int y;
	for (int i = 0; i < size; i++)
	{
		cout << "输入第" << i + 1 << "项的系数和指数：";
		cin >> x >> y;
		termArray[i] = Term(x, y);
	}
}

Poly& Poly::mutiply(Poly& b)
{
	Poly c(size*b.size);
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < b.size; j++)
		{
			c.termArray[count].coef = termArray[i].coef*b.termArray[j].coef;
			c.termArray[count].exp = termArray[i].exp + b.termArray[j].exp;
			count++;
		}
	}
	c.modify();
	return c;
}

void Poly::modify()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (termArray[i].exp == termArray[j].exp)
			{
				termArray[j].coef += termArray[i].coef;
				remove(i);
				i--;
			}
		}
	}
}

void Poly::remove(int index)
{
	size -= 1;
	for (int i = index; i < size; i++)
	{
		termArray[i] = termArray[i + 1];
	}
	
}

void Poly::print()
{
	cout << termArray[0].coef << "x^" << termArray[0].exp;
	for (int i = 1; i < size; i++)
	{
		cout << " + " << termArray[i].coef << "x^" << termArray[i].exp;
	}
	cout << endl;
}

void main()
{
	int size;
	cout << "输入多项式A的大小：";
	cin >> size;
	Poly a(size);
	a.input();
	a.print();

	cout<<"输入多项式B的大小：";
	cin >> size;
	Poly b(size);
	b.input();
	b.print();

	cout << "A*B的结果为：";
	Poly c = a.mutiply(b);
	c.print();

	system("pause");
}