#include <stdio.h>
#include <stdlib.h>
//����ƥ������
bool isValid(string str)
{
	std::stack<char>    s;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		char ch = str[i];//ȡ�ַ� i
		switch (ch)
		{
		case '(': case '[': case '{':
			s.push(ch);
			break;
		case ')': case ']': case '}':{

					  if (s.empty())
					  {
						  return false;
					  }
					  char left = s.top; s.pop;
					  if (!((left == '(' &&  ch == ')')
						  || (left == '[' &&  ch == ']')
						  || (left == '{' &&  ch == '}')))
					  {
						  return false;
					  }
					  break;
		}
		}
	}
	if (!s.empty())
	{
		return false;
	}
	return true;
}

//ʵ����Сջ
class MinStack {
public:
	stack<int>  normal;
	stack<int>  min;

	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x)
	{
		normal.push(x);
		if (min.empty() || x <= min.top()) 
		{
			min.push(x);
		}
		else 
		{
			min.push(min.top());
		}
	}

	void pop() 
	{
		normal.pop();
		min.pop();
	}

	int top() 
	{
		return normal.top();
	}

	int getMin()
	{
		return min.top();
	}
};

//ѭ������
class MyCircularQueue {
	int *array;
	int capacity;
	int front;
	int rear;
	int size;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k)
	{//��ʼ��
		array = (int *)malloc(sizeof(int)*k);
		capacity = k;
		size = 0;
		front = 0;
		rear = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) 
	{//����
		if (size >= capacity)
		{
			return false;
		}
		array[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() 
	{//ɾ��
		if (size == 0)
		{
			return false;
		}
		front= (front + 1) % capacity;
		size--;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() 
	{
		if (size == 0)
		{
			return -1;
		}
		return array[front];
	}

	/** Get the last item from the queue. */
	int Rear() 
	{
		if (size == 0)
		{
			return -1;
		}
		int index = (rear + capacity - 1) % capacity;
		return array[index];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return size = capacity;
	}
};
int main()
{

}