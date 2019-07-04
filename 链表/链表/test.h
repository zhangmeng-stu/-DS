#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node *next;  // 下一个结点的线索
						// 当 next == NULL 时，表示没有后续结点了
						// 反过来说，最后一个结点的 next 一定 == NULL
}Node;

//头插
Node *ListPushFront(Node* head, int val);
 

//尾插
Node *ListPushBack(Node*head, int val);


//遍历
void ListPrint(Node *head);


//头删
Node *ListPopFront(Node*head);


//尾删
Node *ListPopBack(Node*head);