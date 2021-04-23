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
	BinaryTree() { root = NULL; }
	bool isEmpty();
	bool isFull();
	void preorder();
	void inorder();
	void postorder();
	void makeEmpty();
protected:
	TNode* root;
	void preorder_rec(TNode* p);
	void inorder_rec(TNode* p);
	void postorder_rec(TNode* p);
	void makeEmpty_rec(TNode* p);
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

bool BinaryTree::isFull() 
{ 
	return false; 
}

bool BinaryTree::isEmpty()
{
	return root == NULL;
}

void BinaryTree::preorder()
{
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
		cout << " " << p->data;
		preorder_rec(p->left);
		preorder_rec(p->right);
	}
}

void BinaryTree::inorder()
{
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
		cout << " " << p->data;
		inorder_rec(p->right);
	}
}


void BinaryTree::postorder()
{
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
		cout << " " << p->data;
	}
}


void BinaryTree::makeEmpty()
{
	TNode* p = root;
	makeEmpty_rec(p);
	root = NULL;
}

void BinaryTree::makeEmpty_rec(TNode* p)
{
	if (p != NULL)
	{
		makeEmpty_rec(p->left);
		makeEmpty_rec(p->right);
		delete p;
	}
}



class BinarySearchTree : public BinaryTree
{
public:
	BinarySearchTree() : BinaryTree() {}
	bool search(int item);
	void addNode(int item);
	void deleteNode(int item);
	void DeleteEven();
	void DeleteDublicate();
	void FindMiddle();
	bool checkBalance(TNode* p);
	int Diff(TNode* p);
	int height(TNode* p);
protected:
	bool search_rec(int item, TNode* p);
	TNode* addNode_rec(int item, TNode* p);
	TNode* deleteNode_rec(int item, TNode* p);
	TNode* delete_NodeFound(TNode* p);
	void deleteeven_rec(TNode* p);
	void deletedublicate_rec(TNode* p);
	int findmiddle_rec(TNode* p, int mid, int prev);
	int isBalanced(TNode* p);
	TNode* MakeBalanced_rec(TNode* p);
	TNode* LL(TNode* p);
	TNode* RR(TNode* p);
};


bool BinarySearchTree::checkBalance(TNode* p)
{
	if (p == NULL)
		return true;
	int result = isBalanced(p);
	if (result > 0)
		return true;
	return false;
}

int BinarySearchTree::isBalanced(TNode* p)
{
	if (p == NULL)
		return 0;
	int leftH = isBalanced(p->left);
	if (leftH == -1)
		return -1;
	int rightH = isBalanced(p->right);
	if (rightH == -1)
		return -1;
	int diff = leftH - rightH;
	if (abs(diff) > 1)
		return -1;
	return 1 + max(leftH, rightH);
}


bool BinarySearchTree::search(int item)
{
	return search_rec(item, root);
}


bool BinarySearchTree::search_rec(int item, TNode* p)
{
	if (p == NULL)
		return false;
	if (p->data == item)
		return true;
	else
	{
		if (p->data > item)
			return search_rec(item, p->left);
		else
			return search_rec(item, p->right);
	}
}



TNode* BinarySearchTree::RR(TNode* p)
{
	if (p->data == p->right->data) return p;
	TNode* t = p->right;
	p->right = t->left;
	t->left = p;
	return t;
}


TNode* BinarySearchTree::LL(TNode* p)
{
	TNode* t = p->left;
	p->left = t->right;
	t->right = p;
	return t;
}



int BinarySearchTree::height(TNode* p)
{
	if (p == NULL)
		return 0;
	int left = height(p->left);
	int right = height(p->right);
	return 1 + max(left, right);
}


int BinarySearchTree::Diff(TNode* p)
{
	return height(p->left) - height(p->right);
}

 
TNode* BinarySearchTree::MakeBalanced_rec(TNode* p)
{
	if (Diff(p) > 1)
	{
		if (Diff(p->left) >= 0)
			p = LL(p);
		else
		{
			p->left = RR(p->left);
			p = LL(p);
		}
	}
	else if (Diff(p) < -1)
	{
		if (Diff(p->right) <= 0)
			p = RR(p);
		else
		{
			p->right = LL(p->right);
			p = RR(p);
		}
	}
	return p;
}



void BinarySearchTree::addNode(int item)
{
	root = addNode_rec(item, root);
}

TNode* BinarySearchTree::addNode_rec(int item, TNode* p)
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
	if (!checkBalance(p)) p = MakeBalanced_rec(p);
	return p;
}



void BinarySearchTree::deleteNode(int item)
{
	if (search(item))
		root = deleteNode_rec(item, root);
	else
		cout << "Item not found: item not deleted\n";
}

TNode* BinarySearchTree::deleteNode_rec(int item, TNode* p)
{
	if (item < p->data)
		p->left = deleteNode_rec(item, p->left);
	else if (item > p->data)
		p->right = deleteNode_rec(item, p->right);
	else
		p = delete_NodeFound(p);
	if (!checkBalance(p))
		p = MakeBalanced_rec(p);
	return p;
}




TNode* BinarySearchTree::delete_NodeFound(TNode* p)
{
	if (p->left == NULL)
	{
		TNode* temp = p->right;
		delete p;
		return temp;
	}
	else if (p->right == NULL)
	{
		TNode* temp = p->left;
		delete p;
		return temp;
	}
	else
	{
		TNode* p1 = p->right;
		while (p1->left != NULL)
		{
			p1 = p1->left;
		}
		p->data = p1->data;
		p->right = deleteNode_rec(p->data, p->right);
		return p;
	}
}




void BinarySearchTree::DeleteDublicate()
{
	if (root == NULL)
		cout << "tree is empty\n";
	else
		deletedublicate_rec(root);
}

void BinarySearchTree::deletedublicate_rec(TNode* p)
{
	if (p != NULL)
	{
		deletedublicate_rec(p->right);
		if (p->right != NULL)
		{
			if (p->right->data == p->data)
				p->right = delete_NodeFound(p->right);
			else
			{
				if (p->right->left != NULL)
				{
					TNode* now = p->right->left;
					while (now->left != NULL)
						now = now->left;
					if (now->data == p->data)
						now = delete_NodeFound(now);
				}
			}
		}
		deletedublicate_rec(p->left);
	}

}






void BinarySearchTree::DeleteEven()
{
	if (root == NULL)
		cout << "tree is empty\n";
	else
	{
		while (root->data % 2 == 0)
		{
			root = delete_NodeFound(root);
		}
		deleteeven_rec(root);
	}
}

void BinarySearchTree::deleteeven_rec(TNode* p)
{
	if (p == NULL)
		return;
	deleteeven_rec(p->left);
	deleteeven_rec(p->right);
	if (p->left != NULL && p->left->data % 2 == 0)
		p->left = delete_NodeFound(p->left);
	if (p->right != NULL && p->right->data % 2 == 0)
		p->right = delete_NodeFound(p->right);
	if (!checkBalance(p))
		p = MakeBalanced_rec(p);
}


int main()
{
	BinarySearchTree BST;
	BST.addNode(1);
	BST.addNode(2);
	BST.addNode(3);
	BST.addNode(4);
	BST.addNode(5);
	BST.addNode(6);
	BST.preorder();
	BST.inorder();
	BST.postorder();
	return 0;
}