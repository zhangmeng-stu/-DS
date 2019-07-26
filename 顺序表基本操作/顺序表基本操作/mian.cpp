#include "SeqList.h"
void testSeqList()
{

	SeqList seqList;
	SeqListInit(&seqList);

	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 2);
	SeqListPushFront(&seqList, 3);
	SeqListPushFront(&seqList, 4);
}
int main()
{
	testSeqList();
}