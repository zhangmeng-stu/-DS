#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
}Node;

struct TreeNode* last = NULL;
void flatten(struct TreeNode* root){
	if (root == NULL)
	{
		return;
	}
	flatten(root->left);
	flatten(root->right);
	last = root->right;
	root->right = root->left;
	root->left = NULL;
	while (root->right != NULL)
	{
		root = root->right;
	}
	root->right = last;
}
Node * createNode(int a)
{
	Node * node = (Node *)malloc(sizeof(Node));
	node->val = a;
	node->left = node->right = NULL;

	return node;
}
void test()
{
	Node *a = createNode('1');
	Node *b = createNode('2');
	Node *c = createNode('3');
	Node *d = createNode('4');
	Node *e = createNode('5');
	Node *f = createNode('6');
	a->left = b; a->right = e;
	b->left = c; b->right = d;
	e->left = f; e->right = NULL;

	flatten(a);
}
int main()
{
	test();
	return 0;
}