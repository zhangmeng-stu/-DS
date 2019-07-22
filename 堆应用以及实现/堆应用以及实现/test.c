#include "test.h"


//向下调整
void heapify( int* array, int size,int index)
{
	int left = 2 * index + 1;//该节点左孩子的下标
	int right = 2 * index + 2;//该节点右孩子的下标
	if (left >= right)
	{
		return;
	}
	int min = left;
	if (right < size && array[right] < array[left])
	{
		min = right;
	}
	if (array[index] <= array[min])
	{
		return;
	}
	int t = array[min];
	array[min] = array[index];
	array[index] = t;

	index = min;

	heapify(array, size, min);
}
// 创建堆 
void CreatHeap( int* array, int size)
{
	for (int i = (size - 2)/2; i >= 0; i--)
	{
		heapify(array, size, i);
	}
}

//堆的初始化
void InitHeap(Heap* hp,int* array,int size)
{
	for (int i = 0; i < size; i++) {
		hp->_array[i] = array[i];
	}
	hp->_size = size;

	createHeap(hp->_array, hp->_size);
}
// 向堆中插入值为data的元素 
void InsertHeap(Heap* hp, DataType data)
{
	if (hp == NULL)
	{
		return;
	}
	hp->_array[hp->_size++] = data;
	heapify(hp->_array, hp->_size,hp->_size - 1);
}

// 删除堆顶元素 
void EraseHeap(Heap* hp)
{
	assert(hp->_size > 0);
	if (hp == NULL)
	{
		return;
	}
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;
	heapify(hp->_array, hp->_size, 0);
}

// 获取堆中有效元素个数 
int SizeHeap(Heap* hp)
{
	if (hp == NULL)
	{
		return;
	}
	return hp->_size;
}

// 检测堆是否为空 
int EmptyHeap(Heap* hp)
{
	if (hp == NULL)
	{
		return;
	}
	return hp->_size = 0 ? 1 : 0;
}

// 获取堆顶元素 
DataType TopHeap(Heap* hp)
{
	assert(hp->_size > 0);
	return hp->_array[0];
	
}

// 销毁堆 
void DestroyHeap(Heap* hp)
{
	if (hp == NULL)
	{
		return;
	}
	hp->_size = 0;
}

void printHeap(int*array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", array[i]);
	}
}