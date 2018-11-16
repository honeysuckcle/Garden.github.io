#include<iostream>
#include<cstring>
using namespace std;
class String {
public:
	String(char* init, int m);
	int Length();
	int Find(String pat);
	void Fail();
	~String();
private:
	char* str;
	int* f;
};

String::String(char* init, int m)
{
	str = init;
	f = new int[m];
}

int String::Length()
{
	return strlen(str);
}

int String::Find(String pat)
{
	int j = 0, i = 0;
	int LengthP = pat.Length(), LengthS = Length();
	while ((j < LengthP) && (i < LengthS))
	{
		if (pat.str[j] == str[i])
			j++, i++;
		else
			if (j == 0)
				i++;
			else
				j = pat.f[j - 1] + 1;
	}
	if ((j < LengthP || LengthP == 0))
		return -1;
	else
		return i - LengthP;
}

void String::Fail()
{
	int LengthP = Length();
	f[0] = -1;
	for (int j = 1; j < LengthP; j++)
	{
		int i = f[j - 1];
		while ((*(str + j) != *(str + i + 1)) && (i >= 0))
			i = f[i];
		if (*(str + j) == *(str + i + 1) && (*(str + j + 1) != *(str + i + 2)))
			f[j] = i + 1;
		else
			f[j] = -1;
	}
}

String::~String()
{
	//delete[]f;
}
#include <iostream>
#include "String.h"

using namespace std;


void main()
{
	String a("ababbbbbbbbabcab", 16);
	String b("abc", 3);
	b.Fail();
	cout << a.Find(b);

	system("pause");

	return;
}
