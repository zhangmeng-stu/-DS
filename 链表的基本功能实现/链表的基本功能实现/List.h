#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//����ͷ�ڵ�ĵ����� 
typedef int SDataType;

// �ڵ�ṹ 
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node;


// ��һ������ṹ 
typedef struct SList
{
	Node* _pHead;
}SList;


// ����ĳ�ʼ�� 
void SListInit(SList* pl);

// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, SDataType data);

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl);

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data);

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl);

// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(Node* pos, SDataType data);

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl, Node* pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, SDataType data);

// �������� 
void SListDestroy(SList* pl);

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl);

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl);

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl);

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl);

// ɾ�������е�һ��ֵΪdata�Ľڵ� 
void SListRemove(SList* pl, SDataType data);

// ɾ������������ֵΪdata�Ľڵ� 
void SListRemoveAll(SList* pl, SDataType data);

//4. ��Ϥ˫������Ľṹ����ʵ�ִ�ͷ����˫��ѭ����������»���������
typedef int DLDataType;

typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DLDataType _data;
}DLNode;

// ��ʼ��˫������ 
void DListInit(DLNode* pHead);

// β�� 
void DListPushBack(DLNode* pHead, DLDataType data);

// βɾ 
void DListPopBack(DLNode* pHead);

// ͷ�� 
void DListPushFront(DLNode* pHead, DLDataType data);

// ͷɾ 
void DListPopFront(DLNode* pHead);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ؽڵ��λ�� 
DLNode* DListFind(DLNode* pHead, DLDataType data);

// ��posλ��(����ɹ����½ڵ�ʵ����posǰ)����ֵΪdata��Ԫ�� 
void DListInsert(DLNode* pos, DLDataType data);

// ɾ��posλ�õĽڵ� 
void DListErase(DLNode* pos);

// �������е����нڵ���� 
void DListClear(DLNode* pHead);

// �������� 
void DListDestroy(DLNode** pHead);