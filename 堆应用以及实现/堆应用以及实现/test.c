#include "test.h"


//���µ���
void heapify( int* array, int size,int index)
{
	int left = 2 * index + 1;//�ýڵ����ӵ��±�
	int right = 2 * index + 2;//�ýڵ��Һ��ӵ��±�
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
// ������ 
void CreatHeap( int* array, int size)
{
	for (int i = (size - 2)/2; i >= 0; i--)
	{
		heapify(array, size, i);
	}
}

//�ѵĳ�ʼ��
void InitHeap(Heap* hp,int* array,int size)
{
	for (int i = 0; i < size; i++) {
		hp->_array[i] = array[i];
	}
	hp->_size = size;

	createHeap(hp->_array, hp->_size);
}
// ����в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, DataType data)
{
	if (hp == NULL)
	{
		return;
	}
	hp->_array[hp->_size++] = data;
	heapify(hp->_array, hp->_size,hp->_size - 1);
}

// ɾ���Ѷ�Ԫ�� 
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

// ��ȡ������ЧԪ�ظ��� 
int SizeHeap(Heap* hp)
{
	if (hp == NULL)
	{
		return;
	}
	return hp->_size;
}

// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp)
{
	if (hp == NULL)
	{
		return;
	}
	return hp->_size = 0 ? 1 : 0;
}

// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp)
{
	assert(hp->_size > 0);
	return hp->_array[0];
	
}

// ���ٶ� 
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