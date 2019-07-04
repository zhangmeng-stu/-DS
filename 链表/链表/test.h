#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node *next;  // ��һ����������
						// �� next == NULL ʱ����ʾû�к��������
						// ������˵�����һ������ next һ�� == NULL
}Node;

//ͷ��
Node *ListPushFront(Node* head, int val);
 

//β��
Node *ListPushBack(Node*head, int val);


//����
void ListPrint(Node *head);


//ͷɾ
Node *ListPopFront(Node*head);


//βɾ
Node *ListPopBack(Node*head);