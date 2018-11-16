#include<iostream>
using namespace std;
class DblList;

class DblListNode
{
public:
	DblListNode(int d);
	~DblListNode();
	friend class DblList;
private:
	int data;
	DblListNode *left, *right;
};

class DblList
{
public:
	DblList();
	DblList(int*,int );
	~DblList();
	void remove(DblListNode *x);
	void insert(DblListNode *p, DblListNode *x);
	void concatenate(DblList m);
	void display();

private:
	DblListNode *first;
};

DblList::DblList()
{
	first = new DblListNode(NULL);
}

DblList::DblList(int *list,int n)
{
	DblListNode *pre = first = new DblListNode(*list);
	for (int i = 1; i < n; i++)
	{
		DblListNode *current = new DblListNode(list[i]);
		insert(current, pre);
		pre = current;
	}
}

DblList::~DblList()
{
}

void DblList::insert(DblListNode * p, DblListNode * x)
{
	//insert node p to the right of node x
	p->left = x;
	p->right = x->right;
	x->right->left = p;
	x->right = p;
}

void DblList::concatenate(DblList m)
{
	//add m to *this
	if (m.first == m.first->left)
		return;
	first->left->right = m.first;
	m.first->left->right = first;
	m.first->left = first->left;
	first->left = m.first->left;
}

void DblList::display()
{
	DblListNode *current = first;
	do
	{
		cout << current->data<<" ";
		current = current->right;
	} while (current != first);
}


void DblList::remove(DblListNode * x)
{
	if (x == first)
		cout << "Deletion of header node not permitted\n";
	else
	{
		x->left->right = x->right;
		x->right->left = x->left;
		delete x;
	}
}

DblListNode::DblListNode(int d)
{
	data = d;
	left = right = this;
}

DblListNode::~DblListNode()
{
}

int main()
{
	int a1[] = { 1,2,3,4,5 };
	int a2[] = { 6,7,8,9,10 };
	DblList l1(a1, 5),l2(a2,5);
	cout << "L1:";
	l1.display();
	cout << endl<<"L2:";
	l2.display();
	cout << endl;

	cout << "L1+L2:";
	l1.concatenate(l2);
	l1.display();
	cout << endl;

	cout << "L2+L1:";
	l2.concatenate(l1);
	l2.display();
	cout << endl;

	cin.get();

}