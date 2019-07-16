#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;
}Node;
//1.相交链表
int getLength(struct ListNode *head)
{
	int length = 0;
	for (struct ListNode *cur = head; cur != NULL; cur = cur->next)
	{
		length++;
	}
	return length;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int lengthA = getLength(headA);
	int lengthB = getLength(headB);
	struct ListNode *longer = headA;
	struct ListNode *shorter = headB;

	int diff = lengthA - lengthB;
	if (lengthB > lengthA)
	{
		longer = headB;
		shorter = headA;
		diff = lengthB - lengthA;
	}
	//让长的先走
	for (int i = 0; i < diff; i++)
	{
		longer = longer->next;
	}

	while (longer != shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	
	return longer;
}

//2.判断环节点
bool hasCycle(ListNode *head) {
	if (head == NULL)
	{
		return false;
	}
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	do
	{
		fast = fast->next;
		if (fast == NULL)
		{
			return false;
		}
		fast = fast->next;
		if (fast == NULL)
		{
			return false;
		}
		slow = slow->next;
	} while (fast != slow);
	if (fast = slow)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//3.判断环形链表，并返回第一个节点
ListNode *detectCycle(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	//判断环形链表
	do
	{
		fast = fast->next;
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
		if (fast == NULL)
		{
			return NULL;
		}
		slow = slow->next;
	} while (fast != slow);
	//找环的入口
	struct ListNode *p1 = head;
	struct ListNode *p2 = slow;

	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}


//
Node * createTestList1() {
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 1;

	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 2;

	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 3;

	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 4;

	Node *n5 = (Node *)malloc(sizeof(Node));
	n5->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	return n1;
}
Node * createTestList2() {
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 6;

	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 8;

	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 7;

	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 4;

	Node *n5 = (Node *)malloc(sizeof(Node));
	n5->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	return n1;
}

void test()
{
	Node *head1 = createTestList1();
	Node *head2 = createTestList2();

	Node *result = getIntersectionNode(head1, head2);
	for (Node *cur = result; cur != NULL; cur = cur->next)
	{
		printf("%d\n", cur->val);

	}
	printf("\n");
}
int main()
{
	test();
}