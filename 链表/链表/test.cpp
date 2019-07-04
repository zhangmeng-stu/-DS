#include "test.h"
#include <assert.h>

//ͷ��
Node *ListPushFront(Node* head, int val)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = head;
	return node;
}


//β��
Node *ListPushBack(Node*head, int val)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	if (head == NULL)
	{
		return node;
	}
	else
	{
		Node*cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
		return head;
	}
}

//����
void ListPrint(Node *head)
{
	for (Node*cur = head; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->val);
	}
	printf("NULL\n");
}

//ͷɾ
Node *ListPopFront(Node*head)
{
	assert(head != NULL);
	Node* next = head->next;
	free(head);
	return next;
}


//βɾ
Node *ListPopBack(Node*head)
{
	assert(head != NULL);
	if (head->next == NULL)
	{
		free(head->next);
		return head;
	}
	else
	{
		Node*cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}