#include "List.h"

// ����ĳ�ʼ�� 
void SListInit(SList* pl)
{
	Node *pHead = NULL;
}

// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, SDataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = NULL;
	Node* cur = pl->_pHead;
	if (pl->_pHead != NULL)
	{
		while (cur != NULL)
		{
			cur = cur->_pNext;
		}
		cur->_pNext = node;
	}
	else
	{
		pl->_pHead = node;
	}
}

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl)
{
	assert(pl->_pHead != NULL);
	if (pl->_pHead->_pNext == NULL)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
	}
	else
	{
		Node *cur = pl->_pHead;
		while (cur->_pNext->_pNext != NULL)
		{
			cur = cur->_pNext;
		}
		free(cur->_pNext);
		cur->_pNext = NULL;
	}
	}

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;

	node->_pNext = pl->_pHead;
	node = pl->_pHead;
}

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl)
{
	assert(pl->_pHead != NULL);
	Node* next = pl->_pHead->_pNext;
	free(pl->_pHead);

}

// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(Node* pos, SDataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pos->_pNext;
	pos->_pNext = node;
}

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl, Node* pos)
{
	assert(pl->_pHead != NULL);
	Node* cur = pl->_pHead;
	while (cur != NULL)
	{
		Node* next = pos->_pNext;
		if (cur->_pNext == pos)
		{
			if (pos == pl->_pHead)
			{
				SListPopFront(pl);
			}
			else
			{
				cur->_pNext = next;
				free(pos);
			}
		}
	}
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, SDataType data)
{
	Node * cur = pl->_pHead;
	while (cur != NULL)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		else
		{
			return NULL;
		}
	}
}

// �������� 
void SListDestroy(SList* pl)
{
	Node *cur = pl->_pHead;
	while (cur != NULL)
	{
		cur = cur->_pNext;
		free(cur->_pNext);
		cur->_pNext = NULL;
	}
	free(pl->_pHead);
}

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl)
{
	assert(pl->_pHead != NULL);
	int count = 0;
	for (Node* cur = pl->_pHead; cur != NULL; cur = cur->_pNext)
	{
		count++;
	}
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	return pl->_pHead->_data = NULL ? 1 : 0;
}

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	return pl->_pHead;
}

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl)
{
	return pl->_pHead->_pNext;
}

// ɾ�������е�һ��ֵΪdata�Ľڵ� 
void SListRemove(SList* pl, SDataType data)
{
	assert(pl->_pHead != NULL);
	Node* cur = pl->_pHead;
	while (cur != NULL && cur->_data == data)
	{ 
		SListErase(pl, cur);
	}
}

// ɾ������������ֵΪdata�Ľڵ� 
void SListRemoveAll(SList* pl, SDataType data)
{
	assert(pl->_pHead != NULL);
	Node *prev = pl->_pHead;
	Node *cur = pl->_pHead->_pNext;
	while (cur != NULL)
	{
		if (cur->_data == data)
		{
			prev->_pNext = cur->_pNext;//ɾ��data
		}
		else
		{
			prev = cur;
			cur = cur->_pNext;
		}
	}
	if (pl->_pHead->_data = data)
	{
		pl->_pHead = pl->_pHead->_pNext;
	}
}

// ��ʼ��˫������ 
void DListInit(DLNode* pHead)
{
	DLNode *node = (DLNode*)malloc(sizeof(DLNode));
	node->_data = 0;
	node->_pNext = node;
	node->_pPre = node;
	pHead = node;
}

// β�� 
void DListPushBack(DLNode* pHead, DLDataType data)
{
	DLNode* node = (DLNode*)malloc(sizeof(DLNode));
	node->_data = data;
	node->_pPre = pHead->_pPre;
	node->_pNext = pHead;
	pHead->_pPre->_pNext = node;
	pHead->_pPre = node;

}

// βɾ 
void DListPopBack(DLNode* pHead)
{
	assert(pHead->_pNext != pHead);
	DLNode *prev = pHead->_pPre;
	DLNode *next = prev->_pPre;
	free(prev);
	pHead->_pPre = next;
	next->_pNext = pHead;
}

// ͷ�� 
void DListPushFront(DLNode* pHead, DLDataType data)
{
	DLNode*first = pHead->_pNext;
	DLNode* node = (DLNode*)malloc(sizeof(DLNode));
	node->_data = data;
	pHead->_pNext = node;
	node->_pPre = pHead;
	node->_pNext = first;
	first->_pPre = node;
}

// ͷɾ 
void DListPopFront(DLNode* pHead)
{
	assert(pHead->_pNext != pHead);
	DLNode* head = pHead->_pNext;
	DLNode* prev = head->_pNext;
	free(head);
	pHead->_pNext = prev;
	prev->_pPre = pHead;

}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ؽڵ��λ�� 
DLNode* DListFind(DLNode* pHead, DLDataType data)
{
	DLNode* cur = pHead->_pNext;
	while (cur != pHead)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		cur = cur->_pNext;
	}
	return NULL;

}

// ��posλ��(����ɹ����½ڵ�ʵ����posǰ)����ֵΪdata��Ԫ�� 
void DListInsert(DLNode* pos, DLDataType data)
{
	DLNode* prev = pos->_pPre;
	DLNode* node = (DLNode*)malloc(sizeof(DLNode));
	node->_data = data;
	prev->_pNext = node;
	node->_pPre = prev;
	node->_pNext = pos;
	pos->_pPre = node;
}

// ɾ��posλ�õĽڵ� 
void DListErase(DLNode* pos)
{
	DLNode *head = pos->_pPre;
	DLNode *cur = pos->_pNext;
	free(pos);
	head->_pNext = cur;
	cur->_pPre = head;
}

// �������е����нڵ���� 
void DListClear(DLNode* pHead)
{
	DLNode* cur = pHead->_pNext;
	while (cur != pHead)
	{
		DLNode* next = cur->_pNext;
		cur = NULL;
		cur = next;
	}
	pHead = NULL;
}

// �������� 
void DListDestroy(DLNode* pHead)
{
	DLNode* cur = pHead->_pNext;
	while (cur != pHead)
	{
		DLNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	pHead = NULL;
}