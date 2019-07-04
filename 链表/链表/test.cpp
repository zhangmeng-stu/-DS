#include "test.h"
#include <assert.h>

//Í·²å
Node *ListPushFront(Node* head, int val)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = head;
	return node;
}


//Î²²å
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

//±éÀú
void ListPrint(Node *head)
{
	for (Node*cur = head; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->val);
	}
	printf("NULL\n");
}

//Í·É¾
Node *ListPopFront(Node*head)
{
	assert(head != NULL);
	Node* next = head->next;
	free(head);
	return next;
}


//Î²É¾
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