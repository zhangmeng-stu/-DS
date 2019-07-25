#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#if 0
typedef STDataType;
typedef struct Stack{
	STDataType* array;
	size_t top;
	size_t capacity;
}Stack;

//初始化
void StackInit(Stack *ps)
{
	assert(ps);
	ps->array = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
//销毁栈
void StackDestory(Stack *ps)
{
	assert(ps);
	if (ps->array != NULL)
	{
		free(ps->array);
		ps->array = NULL;
		ps->top = 0;
		ps->capacity = 0;

	}

}
//压栈
void Stackpush(Stack *ps, STDataType* val)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 2 : ps->capacity * 2;
		ps->array = (STDataType*)realloc(ps->array, newcapacity*sizeof(STDataType));
		ps->capacity = newcapacity;
	}
	ps->array[ps->top] = val;
	ps->top++;
}

//出栈
void Stackpop(Stack *ps)
{
	assert(ps&&ps->top > 0);
	ps->array[--ps->top];
}

STDataType Stacktop(Stack *ps)
{
	assert(ps&&ps->top > 0);
	return ps->array[ps->top - 1];
}
//求栈中元素
int StackSize(Stack *ps)
{
	assert(ps);
	return ps->top;
}

//判断栈是否为空
int StackEmpty(Stack *ps)
{
	assert(ps);
	return ps->top == 0 ? 0 : 1;
}
#endif
typedef QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	QNode *node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	if (q->_front == NULL)
	{
		q->_front == node;
	}
	else
	{
		q->_rear->_pNext = node;
	}
	q->_rear = node;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q->_front->_data != NULL);
	QNode*next = q->_front->_pNext;
	free( q->_front );
	q->_front = next;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q->_front->_data != NULL);
	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q->_front->_data != NULL);
	int size = 0;
	QNode *cur = q->_front;
	while (cur != NULL)
	{
		size++;
		cur = cur->_pNext;
	}
	return size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->_front != NULL ? 0 : 1;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	if (q->_front != NULL)
	{
		q->_rear = q->_front->_pNext;
		free(q->_front);
		q->_front = q->_rear = NULL;
	}

}