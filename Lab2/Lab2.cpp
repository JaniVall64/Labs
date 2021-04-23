#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;

struct TNode {
	int data;
	TNode* left;
	TNode* right;
	TNode();
	TNode(int d);
};

class BinaryTree {
public:
	void preorder();
	void inorder();
	void postorder();
protected:
	TNode* root;
	void preorder_rec(TNode* p);
	void inorder_rec(TNode* p);
	void postorder_rec(TNode* p);
};

TNode::TNode()
{
	data = 0;
	left = right = NULL;
}

TNode::TNode(int item)
{
	data = item;
	left = right = NULL;
}


void BinaryTree::preorder()
{
	cout << "   preorder sequence of nodes: \n";
	if (root == NULL)
		cout << "tree is empty\n";
	else
	{
		preorder_rec(root);
		cout << ";\n";
	}
}

void BinaryTree::preorder_rec(TNode* p)
{
	if (p != NULL)
	{
		cout << ", " << p->data;
		preorder_rec(p->left);
		preorder_rec(p->right);
	}
}

int main()
{
    std::cout << "Hello World!\n";
}

