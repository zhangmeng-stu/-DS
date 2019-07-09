#include <stdio.h>
#include <stdlib.h>

struct ListNode{
	int val;	
	struct ListNode *next;
};

//1.在有序链表中，删除重复结点（不保留重复结点）
typedef struct ListNode  Node;
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	ListNode *prev = NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;
	while (p2 != NULL)
	{
		if (p1->val != p2->val)
		{
			
			prev = p1; 
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			while (p2 != NULL && p2->val == p1->val)
			{
				p2 = p2->next;
			}
			if (prev != NULL)
			{
				prev->next = p2;
			}
			else
			{
				pHead = p2;
			}
			p1 = p2;
			if (p2 != NULL)
			{
				p2 = p2->next;
			}
		}
	}
	return pHead;
}

//2.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
//法一
//
ListNode* middleNode1(ListNode* head) 
{
	int count = 0;
	for (Node *cur = head; cur != NULL; cur = cur->next)
	{
		count++;
	}
	Node *p = head;
	for (int i = 0; i < count / 2; i++)
	{
		p = p->next;
	}
	return p;
}
//法二
//双指针遍历。快慢指针

ListNode* middleNode2(ListNode* head)
{
	Node *fast = head;
	Node *slow = head;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

//输入一个链表，输出该链表中倒数第k个结点。
//方法1
ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k) {
	int count = 0;
	for (struct ListNode *cur = pListHead; cur != NULL; cur = cur->next)
	{
		count++;
	}
	if (count < k)
	{
		return NULL;
	}
	else{
		struct ListNode *p = pListHead;
		for (int i = 0; i <count - k; i++)
		{
			p = p->next;
		}
		return p;
	}
	
}

//方法2

ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
	ListNode *front = pListHead;
	ListNode *back = pListHead;

	for (int i = 0; i < k; i++) {
		if (front == NULL) {
			return NULL;
		}
		front = front->next;
	}

	// front == NULL 表示链表长度就是 k 个
	while (front != NULL) {
		front = front->next;
		back = back->next;
	}

	return back;
}


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

void test() 
{
	Node *head = createTestList1();

	//Node *result = deleteDuplication(head);
	//Node *result = middleNode2(head);
	Node *result = FindKthToTail2(head,3);



	for (Node *cur = result; cur != NULL; cur = cur->next) {
		printf("%d ", cur->val);
	}
	printf("\n");
}

int main()
{
	test();
}