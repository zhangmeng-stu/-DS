#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
	char val;
	struct Node *left;
	struct Node *right;
}Node;

//前序遍历
void preorederTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//根
	printf("%c", root->val);
	//左子树遍历
	preorederTraversal(root->left);
	//右子树遍历
	preorederTraversal(root->right);
}

//中序遍历
void inorederTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//左子树遍历
	inorederTraversal(root->left);
	//根
	printf("%c", root->val);
	//右子树遍历
	inorederTraversal(root->right);
}

//后序遍历
void pustorederTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//左子树遍历
	pustorederTraversal(root->left);
	//右子树遍历
	pustorederTraversal(root->right);
	//根
	printf("%c", root->val);
}

//求二叉树的节点
int getNodecount(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = getNodecount(root->left);
	int right = getNodecount(root->right);
	return left + 1 + right;

}

//求二叉树的高度
int Max(int a, int b)
{
	return a >= b ? a : b;
}
int getHeight(Node *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return Max(left, right)+1;
}

//求二叉树的节点个数
int getLeafCount(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		int left = getLeafCount(root->left);
		int right = getLeafCount(root->right);
		return left + right;
	}
}

//求子层节点
int getKLevelCount(Node *root, int k)
{
	assert(k >= 1);
	if (root == NULL)
	{
		return 0;
	}
	else if (k == 1)
	{
		return 1;
	}
	else
	{
		return getKLevelCount(root->left, k - 1) +
			getKLevelCount(root->right, k - 1);
	}
}

//在二叉树中查找一个数
Node *find(Node *root, char v)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->val == v)
	{
		return root;
	}
	Node *left = find(root->left, v);
	if (left != NULL)
	{
		return left;
	}
	Node *right = find(root->right, v);
	if (right != NULL)
	{
		return right;
	}
	else
	{
		return NULL;
	}
}

//层序遍历

#include <queue>

void levelorderTravaler(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	std::queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		Node *front = q.front();
		q.pop();
		printf("%c", front->val);
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

//判断二叉树是不是完全二叉树
int BinaryTreeCoplete(Node *root)
{
	if (root == NULL)
	{
		return true;
	}
	std::queue<Node *> q;
	q.push(root);
	while (true) {
		Node * front = q.front(); 
		q.pop();
		if (front == NULL) {
			break;
		}

		q.push(front->left);
		q.push(front->right);
	}

	while (!q.empty()) {
		Node * front = q.front(); q.pop();
		if (front != NULL) {
			return false;
		}
	}

	return true;
}
//创建节点
Node * createNode(char ch) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->val = ch;
	node->left = node->right = NULL;

	return node;
}
void test()
{
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

	preorederTraversal(a);
	printf("\n");
	inorederTraversal(a);
	printf("\n");
	pustorederTraversal(a);
	printf("\n");

	printf("结点个数: %d\n", getNodecount(a));
	printf("高度:%d\n", getHeight(a));
	printf("叶子节点的个数：%d\n", getLeafCount(a));

	printf("第一层结点的个数：%d\n", getKLevelCount(a, 1));
	printf("第二层结点的个数：%d\n", getKLevelCount(a, 2));
	printf("第三层结点的个数：%d\n", getKLevelCount(a, 3));

	printf("层序遍历: "); levelorderTravaler(a); printf("\n");

	if (BinaryTreeCoplete(a)) {
		printf("A 是完全二叉树\n");
	}
	else {
		printf("A 不是完全二叉树\n");
	}
}
int main()
{
	test();
}
