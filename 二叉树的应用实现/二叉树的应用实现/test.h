#include <stdio.h>
#include <stdbool.h>
typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTDataType data;
}BTNode;


// 1. ���������� 
BTNode* CreateBinTree(BTDataType* array, int size);

// ���������� 
BTNode* CopyBinTree(BTNode* pRoot);

// ���ٶ����� 
void DestroyBinTree(BTNode* pRoot);
// �����������ֱ�����ʽ 
void PreOrder(BTNode* pRoot);
void PreOrderNor(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PostOrder(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);
void LevelOrder(BTNode* pRoot);

// ��ȡ�������нڵ�ĸ��� 
int GetNodeCount(BTNode* pRoot);

// ��������ĸ߶� 
int Height(BTNode* pRoot);

// ���������Ƿ�ƽ��O(N^2) 
int IsBalanceTree(BTNode* pRoot);
// ���������Ƿ�ƽ��O(N) 
bool IsBalanceTree_P(BTNode* pRoot, int* height);

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(BTNode* pRoot);

// ��ȡ��������K��ڵ�ĸ��� 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// ��ȡ��������ĳ���ڵ��˫�׽ڵ� 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);

// ��������ľ��� 
void Mirror(BTNode* pRoot);
