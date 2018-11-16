#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

class Node {
	int data;
	Node *next;
	friend class List;
public:
	int getData() { return data; }
};

class List {
private:
	Node *start;
public:
	List();
	void  push(int);
	int length();
	Node *at(int);
	void remove(Node*);
	Node *previous(Node*);
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
	Node *p = start;
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

Node * List::at(int index)
{
	if (index <= 0 || index > length())
	{
		cout << "出界\n";
		return NULL;
	}

	Node *p = start;
	for (int i = 0; i < index; i++)
	{
		p = p->next;
	}
	return p;
}

void List::remove(Node *nowp)
{
	if (nowp == start)
	{
		start = start->next;
		delete nowp;
		return;
	}
	int len = length();
	Node *p = previous(nowp);
	p->next = nowp->next;
	delete nowp;
}

Node * List::previous(Node *nowp)
{
	Node *p = start;
	while (p->next != nowp)
	{
		p = p->next;
	}
	return p;
}

void main()
{
	List list;
	srand(time(0));
	int n = rand() % 100;
	cout << "链表长度为：" << n << endl;
	for (int i = 0; i < n; i++)
	{
		list.push(i+1);
	}
	int index = rand() % n;
	cout << "删除第" << index << "个节点\n";
	list.remove(list.at(index));
	int d = list.at(index)->getData();
	cout << "删除后第" << index << "个节点存的数字是：" << d << endl;
	if (d == index+1)
		cout << "删除成功\n";
	cin.get();
}


