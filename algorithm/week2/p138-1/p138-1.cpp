#include<iostream>
#include"Stack.h"

using namespace std;

void main()
{
	Stack <int> s(10);
	Stack <int> a(10);
	Stack <int> b(10);


	//初始化栈s,a,b
	for (int i = 0; i < 10; i++)
		s.Add(i);

	for (int i = 0; i < 5; i++)
		a.Add(i);


	for (int i = 0; i < 5; i++)
		b.Add(5 + i);

	//合并a,b
	a.Join(b);
	a.Output();// 4 3 2 1 0
	cout << endl;


	//清空栈a,b,只能从栈顶删除
	for (int i = 9; i >= 0; i--)
		a.Delete(i);
	for (int i = 9; i >= 5; i--)
		b.Delete(i);

	s.Divide(a, b);

	a.Output();
	cout << endl;
	b.Output();//Empty

	system("pause");
	return;

}
