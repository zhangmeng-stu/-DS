#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};
typedef struct ListNode Node;


//给定x为基准分割链表为两部分，所有小于x的节点排在大于等于x的节点
// Node *partition(Node *phead, int x)
//{
//	 if (phead == NULL){
//		 return phead;
//	 }
//	Node *small = NULL;
//	Node *smalllast = NULL;
//	Node *big = NULL;
//	Node *biglast = NULL;
//	Node *cur = phead;//遍历整个链表
//	while (cur != NULL)
//	{
//		if (cur->val < x)
//		{
//			//把比x小的值尾插到small上
//			Node *next = cur->next;
//			cur->next = NULL;
//			if (small == NULL)
//			{
//				small = cur;
//			}
//			else
//			{
//				smalllast->next = cur;
//			}
//			smalllast = cur;
//			cur = next;
//		}
//		else
//		{
//			//把大于等于x的值尾插到big上
//			Node *next = cur->next;
//			cur->next = NULL;
//			if (big == NULL)
//			{
//				big = cur;
//			}
//			else
//			{
//				biglast->next = cur;
//			}
//			biglast = cur;
//			cur = next;
//		}
//		}
//	if (small == NULL)
//	{
//		return big;
//	}
//	else
//	{
//		smalllast->next = big;
//		return small;
//	}
//
//	}

Node * partition(Node *head, int x) {
	// 遍历 head 所代表的链表，把每个结点的值和 x 进行比较
	// 如果小于 x，尾插到一条小于 x 的链表中
	// 如果大于等于 x，尾插到一条大于等于 x 的链表中

	// 先定义两个变量，代表 小于 x 和 大于等于 x 的链表
	Node * small = NULL;	// 小于 x 的链表
	Node * smallLast = NULL;	// 小于 x 的链表的最后一个结点
	Node * big = NULL;		// 大于等于 x 的链表
	Node * bigLast = NULL;		// 大于等于 x 的链表的最后一个结点

	// 通过 cur 来遍历原链表的每个结点
	Node * cur = head;
	while (cur != NULL) {
		if (cur->val < x) {
			Node *next = cur->next;

			cur->next = NULL;
			if (small == NULL) {
				small = cur;
			}
			else {
				smallLast->next = cur;
			}
			smallLast = cur;

			cur = next;

		}
		else {
			// 把 cur 尾插到 big 中



			Node *next = cur->next;

			cur->next = NULL;
			if (big == NULL) {
				big = cur;
			}
			else {
				bigLast->next = cur;
			}
			bigLast = cur;

			cur = next;
		}
	}

	// 注意：一定要保证最终链表的最后一个结点的下一个是 NULL

	// 如果没有 < x 的链表怎么办？
	if (small == NULL) {
		return big;
	}
	else {
		smallLast->next = big;
		return small;
	}
}
 Node * createTestList1() 
 {
	 Node *n1 = (Node *)malloc(sizeof(Node));
	 n1->val = 3;

	 Node *n2 = (Node *)malloc(sizeof(Node));
	 n2->val = 8;

	 Node *n3 = (Node *)malloc(sizeof(Node));
	 n3->val = 4;

	 Node *n4 = (Node *)malloc(sizeof(Node));
	 n4->val = 6;

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
	
		Node *result = partition(head, 5);
	
	for (Node *cur = result; cur != NULL; cur = cur->next) 
	{
	 printf("%d ", cur->val);
    }
	printf("\n");
}

int main()
{
	test();
}