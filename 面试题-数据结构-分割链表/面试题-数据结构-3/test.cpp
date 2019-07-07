#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};
typedef struct ListNode Node;


//����xΪ��׼�ָ�����Ϊ�����֣�����С��x�Ľڵ����ڴ��ڵ���x�Ľڵ�
// Node *partition(Node *phead, int x)
//{
//	 if (phead == NULL){
//		 return phead;
//	 }
//	Node *small = NULL;
//	Node *smalllast = NULL;
//	Node *big = NULL;
//	Node *biglast = NULL;
//	Node *cur = phead;//������������
//	while (cur != NULL)
//	{
//		if (cur->val < x)
//		{
//			//�ѱ�xС��ֵβ�嵽small��
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
//			//�Ѵ��ڵ���x��ֵβ�嵽big��
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
	// ���� head �������������ÿ������ֵ�� x ���бȽ�
	// ���С�� x��β�嵽һ��С�� x ��������
	// ������ڵ��� x��β�嵽һ�����ڵ��� x ��������

	// �ȶ����������������� С�� x �� ���ڵ��� x ������
	Node * small = NULL;	// С�� x ������
	Node * smallLast = NULL;	// С�� x ����������һ�����
	Node * big = NULL;		// ���ڵ��� x ������
	Node * bigLast = NULL;		// ���ڵ��� x ����������һ�����

	// ͨ�� cur ������ԭ�����ÿ�����
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
			// �� cur β�嵽 big ��



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

	// ע�⣺һ��Ҫ��֤������������һ��������һ���� NULL

	// ���û�� < x ��������ô�죿
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