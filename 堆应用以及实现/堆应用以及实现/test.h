#include "stdio.h"
#include "assert.h"
// 要求：用户可以控制创建大堆还是小堆 
typedef int DataType;

typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
}Heap;

// 创建堆 
void CreatHeap( int* array, int size);
//堆的初始化
void InitHeap(Heap* hp, int* array, int size);

// 向堆中插入值为data的元素 
void InsertHeap(Heap* hp, DataType data);

// 删除堆顶元素 
void EraseHeap(Heap* hp);

// 获取堆中有效元素个数 
int SizeHeap(Heap* hp);

// 检测堆是否为空 
int EmptyHeap(Heap* hp);

// 获取堆顶元素 
DataType TopHeap(Heap* hp);

// 销毁堆 
void DestroyHeap(Heap* hp);

//打印
void printHeap(int*array, int size);