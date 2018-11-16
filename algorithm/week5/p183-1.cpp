#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

class Node {
	int data;
	Node *next;
	friend class List;
};

class List {
private:
	Node *start;
public:
	List();
	void  push(int);
	int length();
};

List::List()
{
	Node* n = new Node;
	start = n;
	n->data = 0;
	n->next = NULL;
}

void List::push(int data)
{
	Node *n = new Node;
	n->data = data;
	n->next = NULL;
	Node *p =start;
	while (p->next)
	{
		p = p->next;
	}
	p->next = n;
}

int List::length()
{
	Node *p = start;
	int len = 0;
	while (p->next)
	{
		p = p->next;
		len++;
	}
	return len;
}

void main()
{
	List list;
	srand(time(0));
	int n = rand();
	for (int i = 0; i < n; i++)
	{
		list.push(i);
	}
	cout << "随机数的值：" << n << endl;
	
	cout << "用length（）计算出长度为：" << list.length() << endl;
	cin.get();
}
