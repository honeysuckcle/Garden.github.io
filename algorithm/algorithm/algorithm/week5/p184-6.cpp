#include<iostream>
using namespace std;
class List;
class ListNode
{
	friend class List;
public:
	ListNode(int element = 0) {
		data = element;
		link = 0;
	}
private:
	int data;
	ListNode* link;
};

class List
{
public:
	List(int length, int li, int ri)
	{
		len = length;
		if (length == 0)
			first = l = r = 0;
		else {
			Create(length);
			if ((li + 1 == ri) && li >= 0 && li < length&&ri>0 && ri <= length)
			{
				ListNode *current = first;
				ListNode *previous = 0;
				ListNode *t;

				for (int i = 0; i <= li; i++)
				{
					t = previous;
					previous = current;
					current = current->link;
					previous->link = t;
				}
				l = previous;
				r = current;
			}
			else
				cout << "ERROR !r & l range is wrong!" << endl;
		}

	};

	void Create(int length)
	{
		if (length <= 0)
			return;

		first = new ListNode(1);
		ListNode *current = first;
		for (int j = 1; j < length; j++)
		{
			current->link = new ListNode(j);
			current = current->link;
		}
	}

	void Mrn(int n)
	{
		int lc = 0;
		ListNode *tl = l;

		while (tl)
		{
			lc++;
			tl = tl->link;
		}

		if ((n + lc) >= 10)
		{
			//l最右边的节点
			ListNode *current = r;
			ListNode *previous = l;
			ListNode *t;

			while (current)
			{
				t = previous;
				previous = current;
				current = current->link;
				previous->link = t;
			}
			l = previous;
			r = 0;
		}
		else
		{
			ListNode *current = r;
			ListNode *previous = l;
			ListNode *t;

			for (int i = 0; i < n; i++)
			{
				t = previous;
				previous = current;
				current = current->link;
				previous->link = t;
			}
			l = previous;
			r = current;

		}


	}

	void Mln(int n)
	{
		int lc = 0;
		ListNode *tl = l;

		while (tl)
		{
			lc++;
			tl = tl->link;
		}

		if (n >= lc)
		{

			//r最左边的节点
			ListNode *current = l;
			ListNode *previous = r;
			ListNode *t;
			while (current)
			{
				t = previous;
				previous = current;
				current = current->link;
				previous->link = t;
			}
			r = previous;
			l = 0;
		}
		else
		{
			ListNode *current = l;
			ListNode *previous = r;
			ListNode *t;

			for (int i = 0; i < n; i++)
			{
				t = previous;
				previous = current;
				current = current->link;
				previous->link = t;
			}
			l = current;
			r = previous;

		}

	}

	void view()
	{
		//l及左边的数组
		int array[10] = { 0 };
		int count = 0;

		ListNode *lcurrent = l;
		while (lcurrent)
		{
			array[count] = lcurrent->data;
			count++;
			lcurrent = lcurrent->link;
		}

		for (int i = 0; i < count; i++)
			cout << array[count - i - 1] << " ";

		//r右边的数组
		ListNode *rcurrent = r;
		while (rcurrent)
		{
			cout << rcurrent->data << " ";
			rcurrent = rcurrent->link;
		}

	}
private:
	ListNode *first;
	ListNode *l;
	ListNode *r;
	int len;

};

void main()
{
	List l(10, 4, 5);

	l.Mln(2);
	l.view();
	cout << endl;

	l.Mrn(2);
	l.view();
	cout << endl;

	l.Mln(10);
	l.view();
	cout << endl;

	l.Mrn(10);
	l.view();


	cout << endl;
	system("pause");
	return;
}




