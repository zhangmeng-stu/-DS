#include "test.h"
void test()
{
	Node *head = NULL;//链表初始化
	 ListPrint(head);//遍历
	 //头插
	head = ListPushFront(head, 1);
	head = ListPushFront(head, 2);
	head = ListPushFront(head, 3);

	//尾插
	ListPrint(head);
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	head = ListPushBack(head, 30);
	ListPrint(head);

	//头删
	head = ListPopFront(head);
	head = ListPopFront(head);
	ListPrint(head);


	//尾删
	head = ListPopBack(head);
	head = ListPopBack(head);
	ListPrint(head);
}
int main()
{
	test();
}