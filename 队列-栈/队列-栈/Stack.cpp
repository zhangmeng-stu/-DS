#pragma once

#include <assert.h>
typedef struct Stack{
	int array[100];

	int top;
}Stack;

//��ʼ��
void StackInit(Stack *s)
{
	s->top = 0;
}

//ѹջ
void Stackpush(Stack *s,int val)
{
	s->array[s ->top++];
}

//��ջ
void Stackpop(Stack *s)
{
	assert(s->top > 0);
	s->array[--s->top];
}

//��ջ��Ԫ��
int StackSize(Stack *s)
{
	return s->top;
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *s)
{
	return s->top == 0 ? 0 : 1;
}