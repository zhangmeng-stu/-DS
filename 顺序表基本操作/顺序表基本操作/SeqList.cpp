#include "SeqList.h"
#include <malloc.h>
#define DEFAULT_CAPACITY (16)

//��ʼ��
void SeqListInit(PSeqList ps)
{
	ps->_array = (int *)malloc(sizeof(int)*DEFAULT_CAPACITY);
	ps->_capacity = DEFAULT_CAPACITY;
	ps->_size = 0;
}

//����
void SeqListDestroy(PSeqList ps)
{
	free(ps->_array);
	ps->_size = ps->_capacity = 0;

}

// β�� 
void SeqListPushBack(PSeqList ps, DataType data)
{
	ps->_array[ps->_size] = data;
	ps->_size++;
}
// βɾ 
void SeqListPopBack(PSeqList ps)
{
	assert(ps->_size>0);
	ps->_size--;
}

// ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data)
{
	for (int i = 0; i<ps->_size - 1; i ++ )
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}
// ͷɾ 
void SeqListPopFront(PSeqList ps)
{
	assert(ps->_size>0);
	for (int i = 0; i < ps->_size - 2; i++)
	{
		ps->_array[i] = ps->_array[i + 1];

	}
	ps->_size--;
}

// ����λ�ò��� 
void SeqListInsert(PSeqList ps, int pos, DataType datda)
{
	if (pos<0 || pos>ps->_size)
	{
		printf("�±��Ϸ�\n");
		return;
	}
	if (ps->_size > ps->_capacity)
	{
		int* newArray = (int*)malloc(sizeof(int)* 2 * ps->_capacity);
		for (int i = 0; i < ps->_size; i++)
		{
			newArray[i] = ps->_array[i];
		}
		free(ps->_array);
		ps->_array = newArray;
	}
	for (int i = ps->_size; i < pos; i--)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[pos] = datda;
	ps->_size++;
}

// ����λ��ɾ�� 
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps->_size > 0);
	for (int i = pos; i < ps->_size-2; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

// ���data�ͷ���˳����� 
int SeqListFind(PSeqList ps, DataType data)
{
	for (int i = 0; i < ps->_size ; i++)
	{
		if (ps->_array[i] == data)
		{
			return i;
		}
	}
}

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList ps, DataType data)
{
	int index = SeqListFind(ps, data);
	if (index != -1)
	{
		SeqListErase(ps, index);
	}
}

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	int j = 0;
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] != data)
		{
			ps->_array[j++] = ps->_array[i];
		}
	}
	ps->_size = j;
}

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList ps)
{
	return ps->_size;
}

// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps)
{
	return ps->_capacity;
}

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps)
{
	return ps->_size = 0 ? 1 : 0;
}

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps)
{
	return ps->_array[0];
}

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps)
{
	return ps->_array[ps->_size - 1];
}