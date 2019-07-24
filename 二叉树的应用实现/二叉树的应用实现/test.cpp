#include "test.h"

#include "assert.h"
typedef struct ReturnType{
	BTNode *root;
	int used;
}ReturnType;
// 1. 创建二叉树 
ReturnType CreateBinTree(BTDataType* array, int size)
{
	BTDataType rootValue = array[0];
	if (rootValue == '#')
	{
		ReturnType returnValue;
		returnValue.root = NULL;
		returnValue.used = 1;
		return returnValue;
	}
	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	root->data = rootValue;
	ReturnType left = CreateBinTree(array + 1 + left.used, size - 1 - left.used);
	ReturnType right = CreateBinTree(array + 1 + left.used, size - 1 - left.used);

	root->left = left.root;
	root->right = right.root;

	ReturnType returnValue;
	returnValue.root = root;
	returnValue.used = 1 + left.used + right.used;
	return returnValue;

}

// 拷贝二叉树 
BTNode* CopyBinTree(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	root->data = pRoot->data;

	root->left = CopyBinTree(pRoot->left);
	root->right = CopyBinTree(pRoot->right);
	return root;
}

// 销毁二叉树 
void DestroyBinTree(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		if (pRoot != NULL)
		{
			pRoot = NULL;
		}
		if (pRoot->left != NULL)
		{
			DestroyBinTree(pRoot->left);
			pRoot->left = NULL;
		}
		if (pRoot->right != NULL)
		{
			DestroyBinTree(pRoot->right);
			pRoot->right = NULL;
		}
	}
}
// 二叉树的三种遍历方式 
void PreOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	printf("%d", pRoot->data);
	PreOrder(pRoot->left);
	PreOrder(pRoot->right);

}
#include <stack>
void PreOrderNor(BTNode* pRoot)
{
	BTNode* cur = pRoot;
	std::stack<BTNode*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			printf("%d", cur->data);
			st.push(cur);
			cur = cur->left;
		}
		BTNode *top = st.top();
		st.pop();
		cur = top->right;
	}

}
void InOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	
	InOrder(pRoot->left);
	printf("%d", pRoot->data);
	InOrder(pRoot->right);
}
void InOrderNor(BTNode* pRoot)
{
	BTNode* cur = pRoot;
	std::stack<BTNode*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}
		BTNode *top = st.top();
		printf("%d", cur->data);
		st.pop();
		cur = top->right;
	}

}
void PostOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}

	PostOrder(pRoot->left);
	PostOrder(pRoot->right);
	printf("%d", pRoot->data);
}
void PostOrderNor(BTNode* pRoot)
{
	BTNode* cur = pRoot;
	BTNode* last = NULL;

	std::stack<BTNode*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}
		BTNode *top = st.top();
		if (top->right == NULL || top->right == last)
		{
			st.pop();
			printf("%d", cur->data);
			last = top;
		}
		else
		{
			cur = top->right;
		}
		
	}

}
//层序遍历
#include <queue>
void LevelOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	std::queue<BTNode *> q;
	q.push(pRoot);
	while (!q.empty())
	{
		BTNode *front = q.front(); q.pop();
		printf("%d", front->data);
		if (front->left != NULL)
		{
			q.push(front->left);
		}
		if (front->right != NULL)
		{
			q.push(front->right);
		}
	}

}

// 获取二叉树中节点的个数 
int GetNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int left = GetLeafNodeCount(pRoot->left);
	int right = GetLeafNodeCount(pRoot->right);

	return left + right + 1;
}

// 求二叉树的高度 
int Max(int a, int b)
{
	return a > b ? a : b;
}
int Height(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int left = Height(pRoot->left);
	int right = Height(pRoot->right);
	return Max(left, right) + 1;
}

// 检测二叉树是否平衡O(N^2) }
//求树的深度
int getDepth(BTNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int left = getDepth(pRoot->left);
	int right = getDepth(pRoot->right);

	return Max(left, right) + 1;
}

bool IsBalanceTree(BTNode* pRoot)
{
		if (pRoot == NULL)
		{
			return true;
		}
		if (IsBalanceTree(pRoot->left) == false)
		{
			return false;
		}
		if (IsBalanceTree(pRoot->right) == false)
		{
			return false;
		}
		int left = getDepth(pRoot->left);
		int right = getDepth(pRoot->right);
		int diff = left - right;
		if (diff<-1 || diff>1)
		{
			return false;
		}
		return true;
	}

// 检测二叉树是否平衡O(N)
int max(int *a, int *b)
{
	return *a > *b ? *a : *b;
}
bool IsBalanceTree_P(BTNode* pRoot, int* height)
{
	if (pRoot == NULL)
	{
		height = 0;
		return 0;
	}
	int *heightLeft;
	bool resultLeft = IsBalanceTree_P(pRoot->left, heightLeft);
	int *heightRight;
	bool resultRight = IsBalanceTree_P(pRoot->right, heightRight);
	if (resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) {
		*height = max(heightLeft, heightRight) + 1;
		return true;
	}
	else {
		*height = max(heightLeft, heightRight) + 1;
		return false;

	}
}

// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	else if (pRoot->left == NULL && pRoot->right == NULL)
	{
		return 1;
	}
	else
	{
		int left = GetLeafNodeCount(pRoot->left);
		int right = GetLeafNodeCount(pRoot->right);

		return left + right ;
	}
}

// 获取二叉树第K层节点的个数 
int GetKLevelNodeCount(BTNode* pRoot, int k)
{
	assert(k >= 1);
	if (pRoot == NULL)
	{
		return 0;
	}
	else if (k == 1)
	{
		return 1;
	}
	else
	{
		return GetKLevelNodeCount(pRoot->left, k - 1) + GetKLevelNodeCount(pRoot->right, k - 1);
	}
}

// 获取二叉树中某个节点的双亲节点 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode)
{
	assert(pRoot != NULL);
	BTNode *root = pRoot;
	if (root->data == pNode->data)
	{
		return NULL;
	}
	if (pRoot->left != NULL || pRoot->right != NULL)
	{
		if (pRoot->left->data == pNode->left->data || pRoot->right->data == pNode->right->data)
		{
			return pRoot;
		}
		else
		{
			return GetNodeParent(pRoot->left, pNode);
			return GetNodeParent(pRoot->right, pNode);

		}
	}
	return NULL;
}

// 求二叉树的镜像 
void Mirror(BTNode* pRoot)
{
	if (pRoot != NULL)
	{
		if (pRoot->left != NULL && pRoot->right != NULL)
		{
			BTNode *temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
	
	}
}




