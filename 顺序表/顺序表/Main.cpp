#include "SeqList.h"
void testSeqList()
{
	SeqList seqList;
	SeqListInit(&seqList);//��ʼ��,
	//��ʼ��һ������������ֵ��ֵ����û����

	//ͷ��
	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 2);
	SeqListPushFront(&seqList, 3);
	SeqListPushFront(&seqList, 4);
	SeqListPushFront(&seqList, 5);

	//��ӡ
	SeqListPrint(&seqList);


   //β��
	SeqListPushBack(&seqList, 10);
	SeqListPushBack(&seqList, 20);
	SeqListPushBack(&seqList, 30);
	SeqListPushBack(&seqList, 40);

	SeqListPrint(&seqList);

	//ͷɾ
	SeqListPopFront(&seqList);

	SeqListPrint(&seqList);

	//βɾ
	SeqListPopBack(&seqList);

	SeqListPrint(&seqList);

	SeqListRemove(&seqList,1);

	SeqListPrint(&seqList);
}
int main()
{
	testSeqList();
}