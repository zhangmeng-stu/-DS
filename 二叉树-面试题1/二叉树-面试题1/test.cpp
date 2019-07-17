#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	char val;
	struct TreeNode *left;
	struct TreeNode *right;
}Node;


//1.判断两个树是否相同
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

//2.判断两棵树是否对称
bool isMirror(TreeNode* p, TreeNode* q) {
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
	if (isMirror(p->left, q->right) == false)
		return false;
	if (isMirror(p->right, q->left) == false)
		return false;

	return true;

}
bool isSymmetric(TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}

	return isMirror(root->left, root->right);
}
Node * createNode(char ch) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->val = ch;
	node->left = node->right = NULL;

	return node;
}

//二叉树最大深度
int Max(int a, int b)
{
	return a >= b ? a : b;
}
int maxDepth(TreeNode* root) {

	{
		if (root == NULL)
		{
			return NULL;
		}
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return Max(left, right) + 1;
	}
void test()
{
	Node *a = createNode('1');
	Node *b = createNode('2');
	Node *c = createNode('1');
	Node *d = createNode('1');
	Node *e = createNode('1');
	Node *f = createNode('2');
	a->left = b; a->right = c;
	b->left = NULL; b->right = NULL;
	c->left = NULL; c->right = NULL;
	d->left = e; d->right = f;
	e->left = NULL; e->right = NULL;
	f->left = NULL; f->right = NULL;
	bool result = isSameTree(a, d);
		
}
int main()
{
	test();
}