#include <string>
#include <iostream>

using namespace std;

class String
{
public:
	String();

private:
	char *s;
};

String::String()
{
	s = "hgpjkmngbfhhyusysu";
}

void fail(char *p, int *f);

void main()
{
	String s;
	char *p = "aedyuaeaedyuae";
	int pL = strlen(p);
	int *f = new int[pL];
	fail(p, f);

	cout << "Length of p" << pL << endl;
	for (int i = 0; i < pL; i++)
		cout << f[i] << " ";

	system("pause");
	return;
}

void fail(char *p, int *f)
{
	int pLength = strlen(p);
	f[0] = -1;

	for (int j = 1; j < pLength; j++)
	{
		int i = f[j - 1];
		while ((*(p + j) != *(p + i + 1)) && (i >= 0))
			i = f[i];
		if (*(p + j) == *(p + i + 1))
			f[j] = i + 1;
		else
			f[j] = -1;
	}

	return;
}
