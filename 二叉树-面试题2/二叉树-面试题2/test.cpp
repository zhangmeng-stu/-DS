#include <stdio.h>
#include <math.h>
#include <stdlib.h>c
typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
}Node;

//判断两棵树是否相同
bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
		return false;
	if (isSameTree(p->left, q->left) == false)
		return false;
	if (isSameTree(p->right, q->right) == false)
		return false;

	return true;

}

//另一个树的子树
bool isSubtree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p != NULL && q != NULL)
	{
		if (p->val == q->val && isSameTree(p, q))
		{
			return true;
		}
		if (isSubtree(p->left, q))
		{
			return true;
		}
		if (isSubtree(p->right, q))
		{
			return true;
		}
	}
	return false;
}

//平衡二叉树
int Max(int a, int b)
{
	return a > b ? a : b;
}
//求树的深度
int getDepth(TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = getDepth(root->left);
	int right = getDepth(root->right);

	return Max(left, right) + 1;
}
bool isBalanced(TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	int Left = getDepth(root->left);
	int Right = getDepth(root->right);
	if (abs(Left - Right) > 1)//abs 是 absolute value （绝对值）缩写。
		                      //c++ 中的一个数学函数，计算整型量的绝对值。要
		                      //头文件 #include <cmath> 或 #include <math.h>
	{
		return false;
	}
	return isBalanced(root->left) && isBalanced(root->right);

}

Node * createNode(char ch) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->val = ch;
	node->left = node->right = NULL;

	return node;
}

void test() {
	Node *a = createNode('A');
	Node *b = createNode('B');
	Node *c = createNode('C');
	Node *d = createNode('D');
	Node *e = createNode('E');
	Node *f = createNode('F');
	Node *g = createNode('G');
	Node *h = createNode('H');

	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f; c->right = g;
	d->left = NULL; d->right = NULL;
	e->left = NULL; e->right = h;
	f->left = NULL; f->right = NULL;

	isSameTree(a,c);
}
int main()
{
	test();
}