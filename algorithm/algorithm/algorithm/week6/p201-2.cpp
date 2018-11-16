#include<iostream>
using namespace std;

template <class T>
class Node
{
public:
	Node(const T& e) { data = e; link = nullptr; }
	
	T data;
	Node *link;
};
template<class T>
class LinkedQueue
{
public:
	LinkedQueue();
	~LinkedQueue();
	void push(const T& e);
	bool isEmpty();
	void pop();
	void list();
private:
	Node<T> *front;
	Node<T> *rear;
};

template<class T>
LinkedQueue<T>::LinkedQueue()
{
	front = rear = nullptr;
}

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
	while (front != nullptr)
	{
		Node<T>* p = front;
		front = p->link;
		delete p;
	}
	rear = nullptr;
}

template<class T>
void LinkedQueue<T>::push(const T & e)
{

	if (isEmpty())
		front = rear = new Node<T>(e);
	else
		rear = rear->link = new Node<T>(e);
}

template<class T>
bool LinkedQueue<T>::isEmpty()
{
	if (front == nullptr)
		return true;
	else
		return false;
}

template<class T>
void LinkedQueue<T>::pop()
{
	if (isEmpty())
		cout << "Queue is empty. Cannot delete.\n";
	else
	{ 
		Node<T> *delNode = front;
		front = front->link;
		delete delNode;
	}
}

template<class T>
void LinkedQueue<T>::list()
{
	Node<T> *nowNode = front;
	while (nowNode!=nullptr)
	{
		cout << nowNode->data<<" ";
		nowNode = nowNode->link;
	}

}

int main()
{
	LinkedQueue<int> lq;
	for (int i = 0; i < 10; i++)
		lq.push(i);
	for (int i = 0; i < 10; i++)
	{
		cout << "pop"<<i<<"个元素后的队列：";
		lq.list();
		cout << endl;
		lq.pop();
	}
	cin.get();
}