#pragma once   //��֤ͷ�ļ�ֻʹ��һ��

typedef struct SeqList  //�ṹ��
{
	int* array;       //��¼���ݴ�ŵ�λ��
	int  capacity;   //��¼������
	int  size;      //��¼�������ݸ���
}SeqList;//����typedef�����ٿռ䣬���ͣ�Ϊ���������������

//Ϊ���������������
//typedef struct SeqList SeqList;


//��ʼ��
void SeqListInit(SeqList*seq);

//����
void SeqListDestroy(SeqList *seq);

//ͷ��
void SeqListPushFront(SeqList *seq, int val);

//�����±�������
void SeqListInsert(SeqList *seq, int index,int val);

//��ӡ
void SeqListPrint(SeqList *seq);

//β��
void SeqListPushBack(SeqList *seq, int val);

//ͷɾ
void SeqListPopFront(SeqList *seq);

//βɾ
void SeqListPopBack(SeqList *seq);

//�����±���ɾ��
void SeqListErase(SeqList *seq, int index);

//����
int SeqListFind(SeqList* seq, int val);

// ɾ��˳����е�һ�������� val
void SeqListRemove(SeqList *seq, int val);

// ɾ��˳����е����� val
void SeqListRemoveAll(SeqList *seq, int val);