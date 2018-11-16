#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream>
using namespace std;

class Polynomial;
class Term {
	friend istream& operator>>(istream& is, Polynomial& x);
	friend ostream& operator<<(ostream& is, Polynomial& x);
	friend class Polynomial;
public:
	Term(int c = 0, int e = 0, Term* l = 0) :coef(c), exp(e), link(l) {}
private:
	int coef;
	int exp;
	Term* link;
};

class Polynomial {
	friend istream& operator>>(istream&is, Polynomial& x);
	friend ostream& operator<<(ostream&os, Polynomial& x);

public:
	Polynomial();
	Polynomial(const Polynomial& a);
	const Polynomial &operator=(const Polynomial& a);
	~Polynomial();
	Polynomial operator+(const Polynomial &b) const;
	Polynomial operator-(const Polynomial &b) const;
	Polynomial operator*(const Polynomial &b) const;
	float Evaluate(float x) const;

private:
	Term* header;
	static Term* av;
};
#endif // !Poly

