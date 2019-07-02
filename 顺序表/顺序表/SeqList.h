#pragma once   //保证头文件只使用一次

typedef struct SeqList  //结构体
{
	int* array;       //记录数据存放的位置
	int  capacity;   //记录总容量
	int  size;      //记录已有数据个数
}SeqList;//加上typedef不开辟空间，类型，为类型重新起个名字

//为类型重新起个名字
//typedef struct SeqList SeqList;


//初始化
void SeqListInit(SeqList*seq);

//销毁
void SeqListDestroy(SeqList *seq);

//头插
void SeqListPushFront(SeqList *seq, int val);

//根据下标做插入
void SeqListInsert(SeqList *seq, int index,int val);

//打印
void SeqListPrint(SeqList *seq);

//尾插
void SeqListPushBack(SeqList *seq, int val);

//头删
void SeqListPopFront(SeqList *seq);

//尾删
void SeqListPopBack(SeqList *seq);

//根据下标做删除
void SeqListErase(SeqList *seq, int index);

//查找
int SeqListFind(SeqList* seq, int val);

// 删除顺序表中第一个遇到的 val
void SeqListRemove(SeqList *seq, int val);

// 删除顺序表中的所有 val
void SeqListRemoveAll(SeqList *seq, int val);