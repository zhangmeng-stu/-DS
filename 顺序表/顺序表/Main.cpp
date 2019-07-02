#include "SeqList.h"
void testSeqList()
{
	SeqList seqList;
	SeqListInit(&seqList);//初始化,
	//初始化一定会变更变量的值，值传递没有用

	//头插
	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 2);
	SeqListPushFront(&seqList, 3);
	SeqListPushFront(&seqList, 4);
	SeqListPushFront(&seqList, 5);

	//打印
	SeqListPrint(&seqList);


   //尾插
	SeqListPushBack(&seqList, 10);
	SeqListPushBack(&seqList, 20);
	SeqListPushBack(&seqList, 30);
	SeqListPushBack(&seqList, 40);

	SeqListPrint(&seqList);

	//头删
	SeqListPopFront(&seqList);

	SeqListPrint(&seqList);

	//尾删
	SeqListPopBack(&seqList);

	SeqListPrint(&seqList);

	SeqListRemove(&seqList,1);

	SeqListPrint(&seqList);
}
int main()
{
	testSeqList();
}