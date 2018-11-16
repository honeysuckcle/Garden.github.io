#include <string>
#include <iostream>
using namespace std;
class String
{
public:
	String();
	void frequency();
private:
	char *s;
};

String::String()
{
	//初始化数组
	s = "abcdefgasdbf";
}

void String::frequency()
{
	int l = strlen(s);
	int *frequency = new int[l];
	int *exist = new int[l];

	//frequency,exist数组初始化
	for (int i = 0; i < l; i++)
	{
		frequency[i] = 0;
		exist[i] = 1;
	}

	for (int i = 0; i < l; i++)
	{
		if (exist[i])
			frequency[i]++;

		for (int j = i + 1; j < l; j++)
		{
			if (s[i] == s[j])
			{
				frequency[i]++;
				exist[j] = 0;
			}
		}

	}

	cout << "Char " << "Frequency" << endl;
	for (int i = 0; i < l; i++)
	{
		if (frequency[i])
		{
			cout << s[i] << "    " << frequency[i] << endl;
		}
	}

	delete[]exist;
	delete[]frequency;

	return;
}
