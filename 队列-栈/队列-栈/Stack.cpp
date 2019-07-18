#pragma once

#include <assert.h>
typedef struct Stack{
	int array[100];

	int top;
}Stack;

//初始化
void StackInit(Stack *s)
{
	s->top = 0;
}

//压栈
void Stackpush(Stack *s,int val)
{
	s->array[s ->top++];
}

//出栈
void Stackpop(Stack *s)
{
	assert(s->top > 0);
	s->array[--s->top];
}

//求栈中元素
int StackSize(Stack *s)
{
	return s->top;
}

//判断栈是否为空
int StackEmpty(Stack *s)
{
	return s->top == 0 ? 0 : 1;
}