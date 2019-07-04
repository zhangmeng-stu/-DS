#include <stdio.h>
#include <stdlib.h>




struct ListNode
{
	int val;
	ListNode *next;
};
typedef struct ListNode Node;
struct ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL)
	{
		return NULL;
	}
	Node *prev = head;//忽略头结点
	Node *cur = head->next;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			prev->next = cur->next;
		}
		else
		{
			prev = cur;
		}
		cur = cur->next;
	}

		if (head->val != val)
		{
			return head;
		}
		else
		{
			return head->next;
		}
	
}
	//1.反转链表
//	struct ListNode* reverseList(ListNode* head) {
//		Node *resultHead = NULL;
//		Node *cur = head;
//		while (cur != NULL)
//		{
//			Node *next = cur->next;
//			cur->next = resultHead;
//			resultHead = cur;
//			cur = next;
//		}
//		return resultHead;
//	}
//
//
////2.删除链表中等于给定值val的所有节点
////建立一个新的链表，遇到不等于val就尾插
////方法1
//struct	ListNode* removeElements(ListNode* head, int val) {
//		Node *rHead = NULL;
//		Node *last = NULL;
//		Node *cur = head;
//		while (cur != NULL)
//		{
//			Node *next = cur->next;
//			if (cur->val != val)
//			{
//				if (rHead == NULL)
//				{
//					cur->next = rHead;
//					rHead = cur;
//				}
//				else
//				{
//					cur->next = NULL;
//					last->next = cur;
//				}
//				last = cur;
//			}
//			cur = next;
//		}
//		return rHead;
//	}
//
//
////方法2
//
//
//	Node * createTestList1() {
//		Node *n1 = (Node *)malloc(sizeof(Node));
//		n1->val = 1;
//
//		Node *n2 = (Node *)malloc(sizeof(Node));
//		n2->val = 2;
//
//		Node *n3 = (Node *)malloc(sizeof(Node));
//		n3->val = 3;
//
//		Node *n4 = (Node *)malloc(sizeof(Node));
//		n4->val = 4;
//
//		Node *n5 = (Node *)malloc(sizeof(Node));
//		n5->val = 5;
//
//		n1->next = n2;
//		n2->next = n3;
//		n3->next = n4;
//		n4->next = n5;
//		n5->next = NULL;
//
//		return n1;
//	}
//
//	void testReverseList() {
//		Node *head = createTestList1();
//		for (Node *cur = head; cur != NULL; cur = cur->next) {
//			printf("%d ", cur->val);
//		}
//		printf("\n");
//
//		Node *result = reverseList(head);
//
//		for (Node *cur = result; cur != NULL; cur = cur->next) {
//			printf("%d ", cur->val);
//		}
//		printf("\n");
//	}
	Node * createTestList2() {
		Node *n1 = (Node *)malloc(sizeof(Node));
		n1->val = 1;

		Node *n2 = (Node *)malloc(sizeof(Node));
		n2->val = 2;

		Node *n3 = (Node *)malloc(sizeof(Node));
		n3->val = 6;

		Node *n4 = (Node *)malloc(sizeof(Node));
		n4->val = 3;

		Node *n5 = (Node *)malloc(sizeof(Node));
		n5->val = 4;

		Node *n6 = (Node *)malloc(sizeof(Node));
		n6->val = 5;

		Node *n7 = (Node *)malloc(sizeof(Node));
		n7->val = 6;

		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		n4->next = n5;
		n5->next = n6;
		n6->next = n7;
		n7->next = NULL;

		return n1;
	}
//
void testRemoveAll()
{
	Node *head = createTestList2();

	Node *result = removeElements(head,6);

	for (Node *cur = result; cur != NULL; cur = cur->next) {
		printf("%d ", cur->val);
	}
	printf("\n");
}

int main()
{
	//testReverseList();
	testRemoveAll();
}