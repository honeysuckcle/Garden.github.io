#include"experiment2.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
Term* Polynomial::av = 0;

istream& operator>>(istream& is, Polynomial& x) {
	string all;
	is >> all;
	all.push_back('\0');
	string temp;
	vector<int> vec;
	if (all[0] == 'x')
		all = "1" + all;
	else if (all[0] == '-'&&all[1] == 'x')
		all = "-1" + all.substr(1);
	for (int i = 0; i < all.size(); i++) {
		if (all[i] == '^')
			continue;
		if (all[i] == 'x'&&all[i + 1] != '^') {
			all = all.substr(0, i + 1) + "^1" + all.substr(i + 1);
		}
		if ((all[i] == '+' || all[i] == '-') && all[i + 1] == 'x') {
			all = all.substr(0, i + 1) + "1" + all.substr(i + 1);
		}
		if (all[i] == 'x' || all[i] == '\0') {
			vec.push_back(atoi(temp.c_str()));
			temp.clear();
			continue;
		}
		else if (all[i] == '+' || all[i] == '-') {
			vec.push_back(atoi(temp.c_str()));
			temp.clear();
		}
		temp += all[i];
	}
	if (vec.size() % 2 == 1)
		vec.push_back(0);
	Term* current;
	x.header->link = current = new Term(vec[0], vec[1]);
	for (int i = 1; i < vec.size() / 2; i++) {
		current = current->link = new Term(vec[2 * i], vec[2 * i + 1]);
	}
	current->link = x.header;
	return is;
}

ostream& operator<<(ostream& os, Polynomial& x) {
	Term* current = x.header->link;

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

Polynomial::Polynomial() {
	header = new Term(0, -1);
}

Polynomial::Polynomial(const Polynomial & a)
{
	*this = a;
}

const Polynomial &Polynomial::operator=(const Polynomial & a)
{
	header = new Term(0, -1);
	Term* current = header;
	Term* ai = a.header->link;
	while (ai->exp != -1) {
		current = current->link = new Term(ai->coef, ai->exp);
		ai = ai->link;
	}
	current->link = header;
	return *this;
}

Polynomial::~Polynomial()
{
	if (header->link) {
		Term* last = header->link;
		while (last->link != header)
			last = last->link;
		last->link = av;
		av = header;
		header = 0;
	}
}

Polynomial Polynomial::operator+(const Polynomial & b) const
{
	Term temp;
	Polynomial c;
	Term* ai = header->link;
	Term* bi = b.header->link;
	Term* ci = c.header;
	while (1)
	{
		if (ai->exp == bi->exp) {
			if (ai->exp == -1) {
				ci->link = c.header;
				return c;
			}
			int sum = ai->coef + bi->coef;
			if (sum)
				ci = ci->link = new Term(sum, ai->exp);
			ai = ai->link;
			bi = bi->link;
		}
		else if (ai->exp < bi->exp) {
			ci = ci->link = new Term(bi->coef, bi->exp);
			bi = bi->link;
		}
		else {
			ci = ci->link = new Term(ai->coef, ai->exp);
			ai = ai->link;
		}
	}
}

Polynomial Polynomial::operator-(const Polynomial & b) const
{
	Polynomial c;
	Term* ci = c.header;
	Term* bi = b.header->link;
	while (bi->exp != -1) {
		ci = ci->link = new Term(-bi->coef, bi->exp);
		bi = bi->link;
	}
	ci->link = c.header;
	return *this + c;
}

Polynomial Polynomial::operator*(const Polynomial & b) const
{
	Polynomial c;
	Term* bi = b.header->link;
	while (bi->exp != -1) {
		Term* ai = header->link;
		Polynomial temp;
		Term* ti = temp.header;
		while (ai->exp != -1) {
			int coef = ai->coef*bi->coef;
			int exp = ai->exp + bi->exp;
			ti = ti->link = new Term(coef, exp);
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
	Term* current = header->link;
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