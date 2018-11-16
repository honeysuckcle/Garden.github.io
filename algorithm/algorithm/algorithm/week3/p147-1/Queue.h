#pragma once
template <class Type>
class Queue {
public:
	Queue(int MaxQueueSize);

	bool IsFull();
	void Add(const Type& x);

	bool IsEmpty();
	Type* Delete();
private:
	int front, rear;
	int LastOp;//记录最后一次操作 0为delete 1为add
	Type* queue;
	int MaxSize;
};

template <class Type>
Queue<Type>::Queue(int MaxQueueSize) :MaxSize(MaxQueueSize)
{
	queue = new Type[MaxSize];
	LastOp = 0;
	front = rear = 0;
}

template <class Type>
bool Queue<Type>::IsFull()
{
	if (front == rear && LastOp == 1)
		return 1;
	else
		return 0;
}

template <class Type>
bool Queue<Type>::IsEmpty()
{
	if (front == rear && LastOp == 0)
		return 1;
	else
		return 0;
}


template <class Type>
void Queue<Type>::Add(const Type& x)
{

	if (IsFull())
		cout << "Queue is Full";
	else
	{
		rear = (rear + 1) % MaxSize;
		queue[rear] = x;
		LastOp = 1;
	}
}

template <class Type>
Type* Queue<Type>::Delete()
{

	if (IsEmpty())
	{
		cout << "Queue is Empty";
		return 0;
	}
	else
	{
		front = (front + 1) % MaxSize;
		LastOp = 0;
		//front指向当前元素的上一个元素
		return &queue[front];
	}
}
