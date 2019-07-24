#include <stdio.h>
#include <stdbool.h>
typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTDataType data;
}BTNode;


// 1. 创建二叉树 
BTNode* CreateBinTree(BTDataType* array, int size);

// 拷贝二叉树 
BTNode* CopyBinTree(BTNode* pRoot);

// 销毁二叉树 
void DestroyBinTree(BTNode* pRoot);
// 二叉树的三种遍历方式 
void PreOrder(BTNode* pRoot);
void PreOrderNor(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PostOrder(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);
void LevelOrder(BTNode* pRoot);

// 获取二叉树中节点的个数 
int GetNodeCount(BTNode* pRoot);

// 求二叉树的高度 
int Height(BTNode* pRoot);

// 检测二叉树是否平衡O(N^2) 
int IsBalanceTree(BTNode* pRoot);
// 检测二叉树是否平衡O(N) 
bool IsBalanceTree_P(BTNode* pRoot, int* height);

// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(BTNode* pRoot);

// 获取二叉树第K层节点的个数 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// 获取二叉树中某个节点的双亲节点 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);

// 求二叉树的镜像 
void Mirror(BTNode* pRoot);
