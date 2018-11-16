#pragma once
#include <cmath>

using namespace std;

class Polynomial;
class Term
{
	friend Polynomial;
public:
	Term();
	Term(float c, int e);
private:
	float coef;//系数
	int exp;//指数
};

class Polynomial
{
public:
	Polynomial( int s);
	Polynomial();
	Polynomial(const Polynomial& a);
	void addTerm();
	
	Polynomial Add( Polynomial b);
	Polynomial Multiply(Polynomial b);
	double Evaluate(double x);
	~Polynomial();
private:
	static int free;
	static Polynomial C;
	Term *singleArray;
	int size;
};

Term::Term() {
	coef = 0;
	exp = 0;
}
Term::Term(float c, int e) {
	coef = c;
	exp = e;
}

Polynomial::Polynomial() {
	singleArray = &Term(0, 0);
	size = 0;
}

Polynomial::Polynomial(int s) {

	size = s;
	singleArray = new Term[size];
	
}

Polynomial::Polynomial(const Polynomial& a)
{
	size = a.size;
	singleArray = new Term[size];

	//分配新的内存空间，将指针指向内存空间
	copy(a.singleArray,a.singleArray+a.size, singleArray);
}

void Polynomial::addTerm()
{
	
	for (int i = 0; i < size; i++)
	{
		float c = 0;
		int e = 0;
		cout << "输入系数：";
		cin >> c;
		
		cout << "输入指数：";
		cin >> e;
		singleArray[i].coef=c;
		singleArray[i].exp=e;
	}

}

Polynomial Polynomial::Multiply(Polynomial B) {
	//返回多项式 A * B

	Polynomial C(size*B.size);
	//Polynomial D(size*B.size);

	int count = 0;
	//int real = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < B.size; j++)
		{
			C.singleArray[count].coef = singleArray[i].coef*B.singleArray[j].coef;
			C.singleArray[count].exp = singleArray[i].exp+B.singleArray[j].exp;
			count++;
		}
	}

	
	return C;
}


Polynomial Polynomial::Add(Polynomial B) {
	//返回多项式 A 和 B之和 (A B均不含0项)

	//给多项式C分配内存空间
	 
	Polynomial C(size + B.size);
	//a,b为A和B的扫描指针

	int a = 0;
	int b = 0;

	float c = 0;

	//finish = size -1
	while (a <= (size-1) && b <= (B.size-1))
	{
		if (singleArray[a].exp - B.singleArray[b].exp == 0)
		{
			c = (singleArray[a].coef + singleArray[b].coef);
			//判断一下系数是否为0
			if (c)
			{
				C.singleArray[free].coef = c;
				C.singleArray[free].exp = singleArray[a].exp;
				free++;
			}
			a++;
			b++;
		}
		else {

			if (singleArray[a].exp - B.singleArray[b].exp < 0)
			{
				C.singleArray[free].coef = B.singleArray[b].coef;
				C.singleArray[free].exp = B.singleArray[b].exp;
				free++;
				b++;
			}
			else
			{
				C.singleArray[free].coef = singleArray[a].coef;
				C.singleArray[free].exp = singleArray[a].exp;
				free++;
				a++;
			}
		}


	}//switch 和 while结束

	 //将剩下的项放到多项式 C 
	for (; a <= size-1; a++)
	{
		C.singleArray[free].coef = singleArray[a].coef;
		C.singleArray[free].exp = singleArray[a].exp;
		free++;
	}
	for (; b <= size-1; b++)
	{
		C.singleArray[free].coef = B.singleArray[b].coef;
		C.singleArray[free].exp = B.singleArray[b].exp;
		free++;
	}
		
	
	C.size = free;

	return C;
}


double Polynomial::Evaluate(double x)
{
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		result = result + singleArray[i].coef*pow(x, (double)singleArray[i].exp);
	}

	return result;
}

Polynomial::~Polynomial() {
	//释放内存
	delete[]singleArray;
}