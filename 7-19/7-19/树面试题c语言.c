#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
    struct TreeNode *left;
	struct TreeNode *right;
	
}; 
//前序遍历
//顺序表
int *array = NULL;
int size = 0;

void preorder(struct TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	array[size++] = root->val;//尾插
	preorder(root->left);
	preorder(root->right);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	array = (int*)malloc(sizeof(int)* 10000);
	size = 0;
	preorder(root);
	*returnSize = size;
	return array;

}

//中序遍历
void  inorder(struct TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	array[size++] = root->val;//尾插
	inorder(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){

	array = (int*)malloc(sizeof(int)* 10000);
	size = 0;
	inorder(root);
	*returnSize = size;
	return array;
}

//后序遍历
int *array;
int size = 0;
void postorder(struct TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	array[size++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
	array = (int*)malloc(sizeof(int)* 10000);
	size = 0;
	postorder(root);
	*returnSize = size;
	return array;
}

//相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return q->val == p->val
		&&isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

//对称二叉树
bool isMirror(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return p->val == q->val&&
		isMirror(p->left, q->right)
		&& isMirror(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	return isMirror(root->left, root->right);
}

//另一颗树的子树
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return q->val == p->val
		&&isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

bool find(struct TreeNode*root, struct TreeNode* t)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->val == t->val)
	{
		if (isSameTree(root, t))
		{
			return true;
		}
	}
	bool left = find(root->left, t);
	if (left == true)
	{
		return true;
	}
	return find(root->right, t);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){

	return find(s, t);
}

//平衡二叉树
int Max(int a, int b)
{
	return a > b ? a : b;
}
//求树的深度
int getDepth(struct TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = getDepth(root->left);
	int right = getDepth(root->right);

	return Max(left, right) + 1;
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}
	if (isBalanced(root->left) == false)
	{
		return false;
	}
	if (isBalanced(root->right) == false)
	{
		return false;
	}
	int left = getDepth(root->left);
	int right = getDepth(root->right);
	int diff = left - right;
	if (diff<-1 || diff>1)
	{
		return false;
	}
	return true;
}

