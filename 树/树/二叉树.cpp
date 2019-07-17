#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
	char val;
	struct Node *left;
	struct Node *right;
}Node;

//ǰ�����
void preorederTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//��
	printf("%c", root->val);
	//����������
	preorederTraversal(root->left);
	//����������
	preorederTraversal(root->right);
}

//�������
void inorederTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//����������
	inorederTraversal(root->left);
	//��
	printf("%c", root->val);
	//����������
	inorederTraversal(root->right);
}

//�������
void pustorederTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//����������
	pustorederTraversal(root->left);
	//����������
	pustorederTraversal(root->right);
	//��
	printf("%c", root->val);
}

//��������Ľڵ�
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

//��������ĸ߶�
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

//��������Ľڵ����
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

//���Ӳ�ڵ�
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

//�ڶ������в���һ����
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

//�������

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

//�ж϶������ǲ�����ȫ������
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
//�����ڵ�
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

	printf("������: %d\n", getNodecount(a));
	printf("�߶�:%d\n", getHeight(a));
	printf("Ҷ�ӽڵ�ĸ�����%d\n", getLeafCount(a));

	printf("��һ����ĸ�����%d\n", getKLevelCount(a, 1));
	printf("�ڶ�����ĸ�����%d\n", getKLevelCount(a, 2));
	printf("��������ĸ�����%d\n", getKLevelCount(a, 3));

	printf("�������: "); levelorderTravaler(a); printf("\n");

	if (BinaryTreeCoplete(a)) {
		printf("A ����ȫ������\n");
	}
	else {
		printf("A ������ȫ������\n");
	}
}
int main()
{
	test();
}
