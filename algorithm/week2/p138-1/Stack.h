#pragma once
template <class Type>
class Stack
{
public:
	Stack(int MaxStackSize);

	bool IsFull();
	void Add(const Type& item);

	bool IsEmpty();
	Type* Delete(Type&);

	void Output();

	//this -> a & b ���ڴ���Ĳ����и�ֵ
	void Divide(Stack &a, Stack &b);

	//this = this + c
	void Join(Stack c);


private:
	//topΪ�±�
	int top;
	Type *stack;
	int MaxSize;
};

template <class Type>
void Stack<Type>::Output()
{
	//��ջ����ջ��
	if (IsEmpty())
		cout << "The stack is empty." << endl;
	else
		for (int i = top; i >= 0; i--)
			cout << stack[i] << "    ";

}

template <class Type>
void Stack<Type>::Divide(Stack &a, Stack &b)
{
	//�ж�ԭ�����С
	if (top <= 1)
	{
		cout << "The stack is too small to divide." << endl;
		return;
	}

	//ǰ�벿��->a
	for (int i = 0; i <= top / 2; i++)
		a.stack[i] = this->stack[i];

	a.top = top / 2;

	//��벿��
	for (int i = top / 2 + 1; i <= top; i++)
		b.stack[i - top / 2 + 1] = this->stack[i];

	b.top = top - a.top - 1;

}

template <class Type>
void Stack<Type>::Join(Stack c)
{
	if (MaxSize < top + c.top + 2)
	{
		Stack temp(MaxSize);
		for (int i = 0; i < MaxSize; i++)
			temp.stack[i] = stack[i];

		delete[]stack;
		stack = new Type[MaxSize + c.top + 1];

		for (int i = 0; i < top + 1; i++)
			stack[i] = temp.stack[i];

		for (int i = top + 1; i < top + c.top + 2; i++)
			stack[i] = c.stack[i - top - 1];

	}
	else
		for (int i = top + 1; i < top + c.top + 2; i++)
			stack[i] = c.stack[i - top - 1];

	top = top + c.top + 1;

}

/*����Ȩ��
1.�����±�Խ��
2.���˽�����ݳ�Ա����Ȩ��
*/

//Ŀǰ��ѧ�ļ������ݽṹ�������Ա�

/*
inline ����
�����ڴ����Ϊ�򵥵ĺ���������ջ�ڴ�ռ�ݽ�
*/

template <class Type>
Stack<Type>::Stack(int MaxStackSize) :MaxSize(MaxStackSize)
{
	stack = new Type[MaxStackSize];
	top = -1;
}

template <class Type>
bool Stack<Type>::IsEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class Type>
bool Stack<Type>::IsFull()
{
	if (top == MaxSize - 1)
		return 1;
	else
		return 0;
}

template <class Type>
void Stack<Type>::Add(const Type& item)
{
	if (!IsFull())
		stack[++top] = item;
	else
		cout << "Stack is Full!" << endl;
}

template <class Type>
Type* Stack<Type>::Delete(Type& d)
{
	if (!IsEmpty())
	{
		d = stack[top--];
		return &d;
	}
	else
	{
		cout << "Stack is Empty!" << endl;
		return 0;
	}

}
