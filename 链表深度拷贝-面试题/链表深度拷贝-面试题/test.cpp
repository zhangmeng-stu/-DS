#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode{
	int val;
	struct ListNode *next;
	struct ListNode *random;
}Node;

Node* copyRandomList(Node* head)
{
	//�����µ�����
	Node *cur = head;
	while (cur != NULL)
	{
		Node *node = (Node*)malloc(sizeof(Node));
		node->val = cur->val;

		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	//randomָ��
	cur = head;
	while (cur != NULL) {
		// cur->next ���� cur ��Ӧ���½��
		if (cur->random == NULL) {
			cur->next->random = NULL;
		}
		else {
			cur->next->random = cur->random->next;
		}

		cur = cur->next->next;
	}
	//�ֿ���������
	cur = head;
	Node *newhead = head->next;
	while (cur != NULL)
	{
		Node *node = cur->next;
		cur->next = node->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return newhead;
}


Node *create()
{
	Node *n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;
	Node *n2 = (Node*)malloc(sizeof(Node));
	n2->val = 2;
	Node *n3 = (Node*)malloc(sizeof(Node));
	n3->val = 3;
	Node *n4 = (Node*)malloc(sizeof(Node));
	n4->val = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	n1->random = n3;
	n2->random = n1;
	n3->random = n3;
	n4->random = NULL;

	return n1;
}
void test()
{
	Node *head = create();
	for (Node * cur = head; cur != NULL; cur = cur->next) {
		printf("%p(%d, %p) ", cur, cur->val, cur->random);
	}
	printf("\n");
	Node *result = copyRandomList(head);

	for (Node * cur = result; cur != NULL; cur = cur->next) {
		printf("%p(%d, %p) ", cur, cur->val, cur->random);
	}
	printf("\n");

}
int main()
{
	test();
}