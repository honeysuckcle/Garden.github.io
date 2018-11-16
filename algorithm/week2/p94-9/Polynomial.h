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
	float coef;//ϵ��
	int exp;//ָ��
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

	//�����µ��ڴ�ռ䣬��ָ��ָ���ڴ�ռ�
	copy(a.singleArray,a.singleArray+a.size, singleArray);
}

void Polynomial::addTerm()
{
	
	for (int i = 0; i < size; i++)
	{
		float c = 0;
		int e = 0;
		cout << "����ϵ����";
		cin >> c;
		
		cout << "����ָ����";
		cin >> e;
		singleArray[i].coef=c;
		singleArray[i].exp=e;
	}

}

Polynomial Polynomial::Multiply(Polynomial B) {
	//���ض���ʽ A * B

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
	//���ض���ʽ A �� B֮�� (A B������0��)

	//������ʽC�����ڴ�ռ�
	 
	Polynomial C(size + B.size);
	//a,bΪA��B��ɨ��ָ��

	int a = 0;
	int b = 0;

	float c = 0;

	//finish = size -1
	while (a <= (size-1) && b <= (B.size-1))
	{
		if (singleArray[a].exp - B.singleArray[b].exp == 0)
		{
			c = (singleArray[a].coef + singleArray[b].coef);
			//�ж�һ��ϵ���Ƿ�Ϊ0
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


	}//switch �� while����

	 //��ʣ�µ���ŵ�����ʽ C 
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
	//�ͷ��ڴ�
	delete[]singleArray;
}