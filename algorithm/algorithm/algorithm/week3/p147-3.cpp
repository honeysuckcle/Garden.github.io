#include<iostream>

using namespace std;


template <class Type>
class Queue {
	//��״���У����Ԫ������ΪMaxSize-1
public:
	Queue(int MaxQueueSize);

	void Add(const Type& x);

	int Size();

	Type* Delete();
private:
	int front, rear;
	Type* queue;
	int MaxSize;
};

template <class Type>
Queue<Type>::Queue(int MaxQueueSize) :MaxSize(MaxQueueSize)
{
	queue = new Type[MaxSize];
	front = rear = 0;
}

template <class Type>
int Queue<Type>::Size()
{
	int c = rear - front;
	if (c >= 0)
		return c;
	else
		return MaxSize + c;

}



template <class Type>
void Queue<Type>::Add(const Type& x)
{
	//front == rearʱ����Ϊ��
	int k = (rear + 1) % MaxSize;
	if (front == k)
		cout << "Queue is Full!";
	else
		queue[rear = k] = x;

}

template <class Type>
Type* Queue<Type>::Delete()
{

	if (front == rear)
	{
		cout << "Queue is Empty";
		return 0;
	}
	else
	{
		front = (front + 1) % MaxSize;
		//frontָ��ǰԪ�ص���һ��Ԫ��
		return &queue[front];
	}
}

void main()
{
	Queue<int> a(10);

	for (int i = 0; i < 9; i++)
		a.Add(i);

	cout << a.Size() << endl;

	for (int i = 0; i < 9; i++)
		a.Delete();

	cout << a.Size() << endl;

	system("pause");
	return;
}
