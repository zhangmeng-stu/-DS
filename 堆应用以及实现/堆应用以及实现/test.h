#include "stdio.h"
#include "assert.h"
// Ҫ���û����Կ��ƴ�����ѻ���С�� 
typedef int DataType;

typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
}Heap;

// ������ 
void CreatHeap( int* array, int size);
//�ѵĳ�ʼ��
void InitHeap(Heap* hp, int* array, int size);

// ����в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, DataType data);

// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp);

// ��ȡ������ЧԪ�ظ��� 
int SizeHeap(Heap* hp);

// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp);

// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp);

// ���ٶ� 
void DestroyHeap(Heap* hp);

//��ӡ
void printHeap(int*array, int size);