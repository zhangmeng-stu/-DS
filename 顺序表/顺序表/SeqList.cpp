#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFAULT_CAPACITY (16)

//��ʼ��
void SeqListInit(SeqList*seq)
{
	seq->array = (int*)malloc(sizeof(int)*DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}

// ��������
void ensureCapacity(SeqList* seq)
{
	int newCapacity = 2 * seq->capacity;
	int *newArray = (int *)malloc(sizeof(int)* newCapacity );
	for (int i = 0; i < seq->size; i++)
	{
		newArray[i] = seq->array[i];
		free(seq->array);
		seq->array = newArray;
	}

}

//����
void SeqListDestroy(SeqList *seq)
{
	free(seq->array);
	seq->capacity = 0;
	seq->size = 0;
}
//ͷ��
void SeqListPushFront(SeqList *seq, int val)// 1
{
	for (int i = seq->size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->size++;
}


//�����±�������
void SeqListInsert(SeqList *seq, int index, int val)
{
	if (index<0 || index>seq->size)
	{
		printf("�±겻�Ϸ���\n");
		return;
	}

	ensureCapacity(seq);//ȷ���ռ������㹻
	
	for (int i = seq->size; i < index; i--)
	{
		seq->array[i] = seq->array[i - 1];
	}
	seq->array[index] = val;
	seq->size++;
}

//β��
void SeqListPushBack(SeqList *seq, int val)
{
	seq->array[seq->size] = val;
	seq->size++;

}

//ͷɾ
void SeqListPopFront(SeqList *seq)
{
	assert(seq->size > 0);
	for (int i = 0; i < seq->size - 1; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

//βɾ
void SeqListPopBack(SeqList *seq)
{
	assert(seq->size > 0);
	seq->size--;
}

//�����±���ɾ��
void SeqListErase(SeqList *seq, int index)
{
	for (int i = index; i < seq->size - 1; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

//��ӡ
void SeqListPrint(SeqList *seq)
{
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d,", seq->array[i]);
	}
	printf("\n");
}
//����
int  SeqListFind(SeqList* seq, int val)
{
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == val)
		{
			return i;
		}
	}
	return -1;
}

// ɾ��˳����е�һ�������� val
void SeqListRemove(SeqList *seq, int val)
{
	int index = SeqListFind(seq, val);
	if (index != -1)
	{
		SeqListErase(seq, index);
	}
}

// ɾ��˳����е����� val
void SeqListRemoveAll(SeqList *seq, int val)
{
	int j = 0;
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] != val)
		{
			seq->array[j++] = seq->array[i];
		}
	}
	seq->size = j;
}