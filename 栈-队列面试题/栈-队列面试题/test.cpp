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

//��ʼ��
void StackInit(Stack *ps)
{
	assert(ps);
	ps->array = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
//����ջ
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
//ѹջ
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

//��ջ
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
//��ջ��Ԫ��
int StackSize(Stack *ps)
{
	assert(ps);
	return ps->top;
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *ps)
{
	assert(ps);
	return ps->top == 0 ? 0 : 1;
}
#endif
typedef QDataType;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}

// ��β����� 
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

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q->_front->_data != NULL);
	QNode*next = q->_front->_pNext;
	free( q->_front );
	q->_front = next;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q->_front->_data != NULL);
	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return q->_front != NULL ? 0 : 1;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	if (q->_front != NULL)
	{
		q->_rear = q->_front->_pNext;
		free(q->_front);
		q->_front = q->_rear = NULL;
	}

}