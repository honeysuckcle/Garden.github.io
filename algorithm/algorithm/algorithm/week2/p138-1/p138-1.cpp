#include<iostream>
#include"Stack.h"

using namespace std;

void main()
{
	Stack <int> s(10);
	Stack <int> a(10);
	Stack <int> b(10);


	//��ʼ��ջs,a,b
	for (int i = 0; i < 10; i++)
		s.Add(i);

	for (int i = 0; i < 5; i++)
		a.Add(i);


	for (int i = 0; i < 5; i++)
		b.Add(5 + i);

	//�ϲ�a,b
	a.Join(b);
	a.Output();// 4 3 2 1 0
	cout << endl;


	//���ջa,b,ֻ�ܴ�ջ��ɾ��
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
