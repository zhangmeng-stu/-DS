#include "List.h"

// 链表的初始化 
void SListInit(SList* pl)
{
	Node *pHead = NULL;
}

// 在链表中尾插值为data的节点 
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

// 删除链表最后一个节点 
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

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;

	node->_pNext = pl->_pHead;
	node = pl->_pHead;
}

// 删除链表中第一个节点 
void SListPopFront(SList* pl)
{
	assert(pl->_pHead != NULL);
	Node* next = pl->_pHead->_pNext;
	free(pl->_pHead);

}

// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, SDataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_pNext = pos->_pNext;
	pos->_pNext = node;
}

// 删除链表中值为data的节点 
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

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
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

// 销毁链表 
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

// 获取链表中有效节点的个数 
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

// 检测链表是否为空 
int SListEmpty(SList* pl)
{
	return pl->_pHead->_data = NULL ? 1 : 0;
}

// 获取链表的第一个节点 
Node* SListFront(SList* pl)
{
	return pl->_pHead;
}

// 获取链表的第二个节点 
Node* SListBack(SList* pl)
{
	return pl->_pHead->_pNext;
}

// 删除链表中第一个值为data的节点 
void SListRemove(SList* pl, SDataType data)
{
	assert(pl->_pHead != NULL);
	Node* cur = pl->_pHead;
	while (cur != NULL && cur->_data == data)
	{ 
		SListErase(pl, cur);
	}
}

// 删除链表中所有值为data的节点 
void SListRemoveAll(SList* pl, SDataType data)
{
	assert(pl->_pHead != NULL);
	Node *prev = pl->_pHead;
	Node *cur = pl->_pHead->_pNext;
	while (cur != NULL)
	{
		if (cur->_data == data)
		{
			prev->_pNext = cur->_pNext;//删除data
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

// 初始化双向链表 
void DListInit(DLNode* pHead)
{
	DLNode *node = (DLNode*)malloc(sizeof(DLNode));
	node->_data = 0;
	node->_pNext = node;
	node->_pPre = node;
	pHead = node;
}

// 尾插 
void DListPushBack(DLNode* pHead, DLDataType data)
{
	DLNode* node = (DLNode*)malloc(sizeof(DLNode));
	node->_data = data;
	node->_pPre = pHead->_pPre;
	node->_pNext = pHead;
	pHead->_pPre->_pNext = node;
	pHead->_pPre = node;

}

// 尾删 
void DListPopBack(DLNode* pHead)
{
	assert(pHead->_pNext != pHead);
	DLNode *prev = pHead->_pPre;
	DLNode *next = prev->_pPre;
	free(prev);
	pHead->_pPre = next;
	next->_pNext = pHead;
}

// 头插 
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

// 头删 
void DListPopFront(DLNode* pHead)
{
	assert(pHead->_pNext != pHead);
	DLNode* head = pHead->_pNext;
	DLNode* prev = head->_pNext;
	free(head);
	pHead->_pNext = prev;
	prev->_pPre = pHead;

}

// 在链表中查找值为data的节点，找到返回节点的位置 
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

// 在pos位置(插入成功后新节点实际在pos前)插入值为data的元素 
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

// 删除pos位置的节点 
void DListErase(DLNode* pos)
{
	DLNode *head = pos->_pPre;
	DLNode *cur = pos->_pNext;
	free(pos);
	head->_pNext = cur;
	cur->_pPre = head;
}

// 将链表中的所有节点清空 
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

// 销毁链表 
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