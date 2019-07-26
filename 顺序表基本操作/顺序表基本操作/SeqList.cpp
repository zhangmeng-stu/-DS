#include "SeqList.h"
#include <malloc.h>
#define DEFAULT_CAPACITY (16)

//初始化
void SeqListInit(PSeqList ps)
{
	ps->_array = (int *)malloc(sizeof(int)*DEFAULT_CAPACITY);
	ps->_capacity = DEFAULT_CAPACITY;
	ps->_size = 0;
}

//销毁
void SeqListDestroy(PSeqList ps)
{
	free(ps->_array);
	ps->_size = ps->_capacity = 0;

}

// 尾插 
void SeqListPushBack(PSeqList ps, DataType data)
{
	ps->_array[ps->_size] = data;
	ps->_size++;
}
// 尾删 
void SeqListPopBack(PSeqList ps)
{
	assert(ps->_size>0);
	ps->_size--;
}

// 头插 
void SeqListPushFront(PSeqList ps, DataType data)
{
	for (int i = 0; i<ps->_size - 1; i ++ )
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}
// 头删 
void SeqListPopFront(PSeqList ps)
{
	assert(ps->_size>0);
	for (int i = 0; i < ps->_size - 2; i++)
	{
		ps->_array[i] = ps->_array[i + 1];

	}
	ps->_size--;
}

// 任意位置插入 
void SeqListInsert(PSeqList ps, int pos, DataType datda)
{
	if (pos<0 || pos>ps->_size)
	{
		printf("下表不合法\n");
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

// 任意位置删除 
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps->_size > 0);
	for (int i = pos; i < ps->_size-2; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

// 检测data释放在顺序表中 
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

// 移除顺序表中第一个值为data的元素 
void SeqListRemove(PSeqList ps, DataType data)
{
	int index = SeqListFind(ps, data);
	if (index != -1)
	{
		SeqListErase(ps, index);
	}
}

// 移除顺序表中所有值为data的元素 
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

// 获取顺序表有效元素个数 
int SeqListSize(PSeqList ps)
{
	return ps->_size;
}

// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps)
{
	return ps->_capacity;
}

// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps)
{
	return ps->_size = 0 ? 1 : 0;
}

// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps)
{
	return ps->_array[0];
}

// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps)
{
	return ps->_array[ps->_size - 1];
}