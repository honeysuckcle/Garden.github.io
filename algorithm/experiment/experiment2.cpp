#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Item
{
public:
	Item(int c = 0, int ex = 0);
	~Item();
	friend class Polynomial;
	friend istream& operator>>(istream& is, Polynomial& x);
	friend ostream& operator<<(ostream& is, Polynomial& x);
private:
	int coef;
	int exp;
	Item* link;
};

Item::Item(int c, int ex)
{
	coef = c;
	exp = ex;
	link = nullptr;
}

Item::~Item()
{
}

class Polynomial
{
public:
	Polynomial() { header = nullptr; };
	~Polynomial() ;
	friend istream& operator>>(istream& is, Polynomial& x);
	friend ostream& operator<<(ostream& is, Polynomial& x);
	Polynomial operator+(const Polynomial &b) const;
	Polynomial operator-(const Polynomial &b) const;
	Polynomial operator*(const Polynomial &b) const;
	float Evaluate(float x) const;
private:
	Item* header;
	
};


Polynomial::~Polynomial() {
	Item* start = header,*p = nullptr;
	while (header&&header->link!=start) {
		p = header;
		header = header->link;
		delete p;
	}
	delete header;
}

istream& operator>>(istream& is, Polynomial& x) {
	int number = 0;
	is >> number;
	
	int co, ex;
	is >> co >> ex;
	Item *item = new Item(co, ex);
	x.header = item;
	Item* current = x.header;
	for (int i = 1; i < number; i++)
	{
		is >> co >> ex;
		Item *item=new Item(co, ex);
		current->link = item;
		current = current->link;
		current->link = x.header;
	}
	
	return is;
}

ostream& operator<<(ostream& os, Polynomial& x) {
	Item* current = x.header;

	if (current == x.header) {
		os << 0 << endl;
		return os;
	}

	if (current->exp == 0)
		os << current->coef;
	else {
		if (current->coef == 1)
			os << 'x';
		else if (current->coef == -1)
			os << "-x";
		else
			os << current->coef << 'x';
		if (current->exp != 1)
			os << '^' << current->exp;
	}
	current = current->link;
	while (current->exp != -1)
	{
		if (current->coef > 0)
			os << "+";
		if (current->exp == 0)
			os << current->coef;
		else {
			if (current->coef == 1)
				os << 'x';
			else if (current->coef == -1)
				os << "-x";
			else
				os << current->coef << 'x';
			if (current->exp != 1)
				os << '^' << current->exp;
		}
		current = current->link;
	}
	os << endl;
	return os;
}
Polynomial Polynomial::operator+(const Polynomial & b) const
{
	Item temp;
	Polynomial c;
	Item* ai = header;
	Item* bi = b.header;
	Item* ci = c.header;
	while (1)
	{
		if (ai->exp == bi->exp) {
			if (ai->exp == -1) {
				ci->link = c.header;
				return c;
			}
			int sum = ai->coef + bi->coef;
			if (sum)
			{ 
				ci = new Item(sum, ai->exp);
				ci = ci->link;
			}
			ai = ai->link;
			bi = bi->link;
		}
		else if (ai->exp < bi->exp) {
			ci = new Item(bi->coef, bi->exp);
			ci = ci->link;
			bi = bi->link;
		}
		else {
			ci = new Item(ai->coef, ai->exp);
			ci = ci->link;
			ai = ai->link;
		}
	}
}

Polynomial Polynomial::operator-(const Polynomial & b) const
{
	Polynomial c;
	Item* ci = c.header;
	Item* bi = b.header->link;
	while (bi->exp != -1) {
		ci = new Item(-bi->coef, bi->exp);
		ci = ci->link;
		bi = bi->link;
	}
	ci->link = c.header;
	return *this + c;
}

Polynomial Polynomial::operator*(const Polynomial & b) const
{
	Polynomial c;
	Item* bi = b.header->link;
	while (bi->exp != -1) {
		Item* ai = header->link;
		Polynomial temp;
		Item* ti = temp.header;
		while (ai->exp != -1) {
			int coef = ai->coef*bi->coef;
			int exp = ai->exp + bi->exp;
			ti = ti->link = new Item(coef, exp);
			ai = ai->link;
		}
		ti->link = temp.header;
		if (c.header->link == NULL)
			c = temp;
		else {
			c = c + temp;
		}
		bi = bi->link;
	}
	return c;
}

float Polynomial::Evaluate(float x) const
{
	float result = 0;
	Item* current = header->link;
	while (current->exp != -1) {
		result += current->coef*pow(x, current->exp);
		current = current->link;
	}
	return result;
}

int main()
{
	cout << "Input a polynomial(a): " << endl;
	Polynomial a;
	cin >> a;
	cout << "Input a polynomial(b): " << endl;
	Polynomial b;
	cin >> b;
	cout << "a + b = ";
	cout << a + b;
	cout << "a - b = ";
	cout << a - b;
	cout << "a * b = ";
	cout << a * b;
	cout << "a(3) = " << a.Evaluate(3) << endl;
	system("pause");
	return 0;
}

