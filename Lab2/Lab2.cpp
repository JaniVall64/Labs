#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>

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

int main()
{
    std::cout << "Hello World!\n";
}

