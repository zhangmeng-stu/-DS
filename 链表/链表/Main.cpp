#include "test.h"
void test()
{
	Node *head = NULL;//�����ʼ��
	 ListPrint(head);//����
	 //ͷ��
	head = ListPushFront(head, 1);
	head = ListPushFront(head, 2);
	head = ListPushFront(head, 3);

	//β��
	ListPrint(head);
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	head = ListPushBack(head, 30);
	ListPrint(head);

	//ͷɾ
	head = ListPopFront(head);
	head = ListPopFront(head);
	ListPrint(head);


	//βɾ
	head = ListPopBack(head);
	head = ListPopBack(head);
	ListPrint(head);
}
int main()
{
	test();
}