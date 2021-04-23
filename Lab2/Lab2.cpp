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
	void addNode(int item);
protected:
	TNode* root;
	TNode* addNode_rec(int item, TNode* p);
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


void BinaryTree::inorder()
{
	cout << "   inorder sequence of nodes: \n";
	if (root == NULL)
		cout << "tree is empty\n";
	else
	{
		inorder_rec(root);
		cout << ";\n";
	}
}

void BinaryTree::inorder_rec(TNode* p)
{
	if (p != NULL)
	{
		inorder_rec(p->left);
		cout << ", " << p->data;
		inorder_rec(p->right);
	}
}


void BinaryTree::postorder()
{
	cout << "   postorder sequence of nodes: \n";
	if (root == NULL)
		cout << "tree is empty\n";
	else
	{
		postorder_rec(root);
		cout << ";\n";
	}
}

void BinaryTree::postorder_rec(TNode* p)
{
	if (p != NULL)
	{
		postorder_rec(p->left);
		postorder_rec(p->right);
		cout << ", " << p->data;
	}
}

void BinaryTree::addNode(int item)
{
	root = addNode_rec(item, root);
}

TNode* BinaryTree::addNode_rec(int item, TNode* p)
{
	if (p == NULL)
	{
		p = new TNode(item);
		p->left = p->right = NULL;
	}
	else if (item < p->data)
		p->left = addNode_rec(item, p->left);
	else
		p->right = addNode_rec(item, p->right);
	
	return p;
}


int main()
{
	BinaryTree BST;
	BST.addNode(1);
	BST.addNode(2);
	BST.addNode(3);
	BST.addNode(4);
	BST.addNode(5);
	BST.addNode(6);
	BST.preorder();
	return 0;
}

