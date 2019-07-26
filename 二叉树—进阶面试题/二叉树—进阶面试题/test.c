#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};

//利用前序和中序构建二叉树
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	if (preorderSize == NULL)
	{
		return NULL;
	}
	int size = preorderSize;
	int rootvalue = preorder[0];
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = rootvalue;
	int leftsize = -1;
	for (int i = 0; i<inorderSize; i++)
	{
		if (inorder[i] == rootvalue)
		{
			leftsize = i;
			break;
		}
	}
	root->left = buildTree(preorder + 1, leftsize, inorder, leftsize);
	root->right = buildTree(preorder + 1 + leftsize, size - 1 - leftsize, inorder + 1 + leftsize, size - 1 - leftsize);

	return root;
}

//利用后序和中序构建二叉树
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){

	if (inorderSize == NULL)
	{
		return NULL;
	}
	int size = inorderSize;
	int rootvalue = postorder[size - 1];
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = rootvalue;
	int leftsize = -1;
	for (int i = 0; i<inorderSize; i++)
	{
		if (inorder[i] == rootvalue)
		{
			leftsize = i;
			break;
		}
	}
	root->left = buildTree(inorder, leftsize, postorder, leftsize);
	root->right = buildTree(inorder + 1 + leftsize, size - 1 - leftsize, postorder + leftsize, size - 1 - leftsize);

	return root;
}

//二叉树的公共祖先
bool exists(struct TreeNode *root, struct TreeNode *q)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->val == q->val)
	{
		return true;
	}
	bool left = exists(root->left, q);
	if (left == true)
	{
		return true;
	}
	return exists(root->right, q);
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == p || root == q)
	{
		return root;
	}
	bool pInleft = exists(root->left, p);
	bool qInleft = exists(root->left, q);

	if (pInleft && qInleft)
	{
		return lowestCommonAncestor(root->left, p, q);
	}
	if (!pInleft && !qInleft)
	{
		return lowestCommonAncestor(root->right, p, q);
	}
	return root;
}

//二叉树创建字符串
char * array;
int size;

void preorder(struct TreeNode *root) {
	if (root == NULL) {
		return;
	}

	// 根
	size += sprintf(array + size, "(%d", root->val);
	if (root->left == NULL && root->right != NULL) {
		size += sprintf(array + size, "()");
		preorder(root->right);
	}
	else if (root->left == NULL && root->right == NULL) {

	}
	else if (root->left != NULL && root->right == NULL) {
		preorder(root->left);
	}
	else {
		preorder(root->left);
		preorder(root->right);
	}

	size += sprintf(array + size, ")");
}

char * tree2str(struct TreeNode *root) {
	array = (char *)malloc(sizeof(char)* 1000000);
	size = 0;

	preorder(root);
	array[size - 1] = '\0';
	return array + 1;
}