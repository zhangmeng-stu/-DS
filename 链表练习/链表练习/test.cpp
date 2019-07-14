#include "stdio.h"
#include "stdlib.h"
typedef  struct Node{
	int val;
	struct Node *next;
}Node;
////找中间节点
//Node *findMiddle(struct Node *head)
//{
//	Node *fast = head;
//	Node *slow = head;
//	while (fast != NULL)
//	{
//		fast = fast->next;
//		if (fast == NULL)
//		{
//			break;
//		}
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return slow;
//}
////链表逆置
//Node *reverseList(struct Node *head)
//{
//	Node *resultList = NULL;
//	Node *cur = head;
//	while (cur != NULL)
//	{
//		Node *next = cur->next;
//		cur->next = resultList;
//		resultList = cur;
//		cur = next;
//	}
//	return  resultList;
//}
////回文结构
//bool chkPalindrome(Node *A)
//{
//	Node *middle = findMiddle(A);
//	Node *result = reverseList(middle);
//
//	Node *c1 = A;
//	Node *c2 = result;
//
//	while (c1 != NULL && c2 != NULL) {
//		if (c1->val != c2->val) {
//			return false;
//		}
//
//		c1 = c1->next;
//		c2 = c2->next;
//	}
//
//	return true;
//}
//	
// write code here
bool chkPalindrome(Node *A)
{
	if (A == NULL)
	{ 
		return false;
	}
	else if (A->next == NULL)
	{
		return true;
	}
//快慢指针找出中间节点
    Node* fast = A;
    Node* slow = A;
    while (fast != NULL )
	{
		fast = fast->next;
			if (fast == NULL)
				{
					break;
				}
				slow = slow->next;
				fast = fast->next;
}
//反转
Node* p = slow->next;
Node* p1 = p->next;
while (p != NULL)
{
	p->next = slow;
	slow = p;
	p = p1;
	p1 = p1->next;
}

while (A != slow)
{
	if ((A->val) != (slow->val))
	{
		return false;
	}
	else{
		if (A->next == slow)
		{
			return true;
		}
		A = A->next;
		slow = slow->next;
	}
}
return true;
}

Node *createList()
{
	Node *n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;
	Node *n2 = (Node*)malloc(sizeof(Node));
	n2->val = 2;
	Node *n3 = (Node*)malloc(sizeof(Node));
	n3->val = 2;
	Node *n4 = (Node*)malloc(sizeof(Node));
	n4->val = 1;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	return n1;

}
void test()
{
	Node *head = createList();
	bool result = chkPalindrome(head);
}

int main()
{
	test();
}