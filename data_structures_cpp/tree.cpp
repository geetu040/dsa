#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *l, *r;
	Node(int data) {
		this->data = data;
		this->l = NULL;
		this->r = NULL;
	}
	Node(int data, int l_data, int r_data) {
		this->data = data;
		this->l = new Node(l_data);
		this->r = new Node(r_data);
	}
};

class Traversal {
public:
	void inorder (struct Node *node) {
		if (node == NULL) {
			return;
		}
		inorder(node->l);
		cout << node->data << " -> ";
		inorder(node->r);
	}
	void preorder (struct Node *node) {
		if (node == NULL) {
			return;
		}
		cout << node->data << " -> ";
		preorder(node->l);
		preorder(node->r);
	}
	void postorder (struct Node *node) {
		if (node == NULL) {
			return;
		}
		postorder(node->l);
		postorder(node->r);
		cout << node->data << " -> ";
	}
	void traverse_all(struct Node *node) {
		cout << endl << "inorder traversal:\t";
		inorder(node);
		cout << endl << "preorder traversal:\t";
		preorder(node);
		cout << endl << "postorder traversal:\t";
		postorder(node);
		cout << endl;
	}
};
class TreeProperties: public Traversal {
public:
	int depth(struct Node *node) {
		int d = 0;
		while (node != NULL) {
			node = node->l;
			d += 1;
		}
		return d;
	}
	int height(struct Node *node) {
		if (node == NULL) 
			return 0;

		int hl, hr;
		hl = height(node->l);
		hr = height(node->r);

		return 1 + ((hl > hr) ? hl : hr) ; // here greater is taken from left or right
	}
	int countNodes(struct Node *node) {
		if (node == NULL)
			return 0;
		return 1 + countNodes(node->l) + countNodes(node->r);
	}
	bool isFullBinaryTree(struct Node *root) {
		// Checking for emptiness
		if (root == NULL)
			return true;

		// Checking for the presence of children
		if (root->l == NULL && root->r == NULL)
			return true;

		if ((root->l) && (root->r))
			return (isFullBinaryTree(root->l) && isFullBinaryTree(root->r));

		return false;
	}
	bool isPerfectBinaryTree (struct Node *node) {
		this -> isPerfectBinaryTree( node, depth(node) );
	}
	bool isPerfectBinaryTree(struct Node *node, int d, int level=0) {
		if (node == NULL)
			return true;
		if (node->l == NULL && node->r == NULL) 
			return (level+1 == d);
		if (node->l == NULL || node->r == NULL)
			return false;

		return (
			isPerfectBinaryTree(node->l, d, level + 1)
			&&
			isPerfectBinaryTree(node->r, d, level + 1)
		);
	}
	bool isCompleteBinaryTree(struct Node *node) {
		if (node == NULL)
			return true;
		return (
			countNodes(node->l) >= countNodes(node->r)
			&&
			isCompleteBinaryTree(node->l)
			&&
			isCompleteBinaryTree(node->r)
		);
	}
	bool isHeightBalanced(struct Node *node) {
		if (node == NULL) 
			return true;
		
		return (
			abs(height(node->l) - height(node->r)) < 2
			&&
			isHeightBalanced(node->l)
			&&
			isHeightBalanced(node->r)
		);
	}
	void getProperties(struct Node *node) {
		cout << "Depth:  " << depth(node)<< endl;
		cout << "Height:  " << height(node)<< endl;
		cout << "Nodes:  " << countNodes(node)<< endl;
		cout << "Full Binary:  " << isFullBinaryTree(node) <<endl;
		cout << "Perfect Binary:  " << isPerfectBinaryTree(node) <<endl;
		cout << "Complete Binary:  " << isCompleteBinaryTree(node) << endl;
		cout << "Height Balanced:  " << isHeightBalanced(node) << endl;

		traverse_all(node);
	}
};

int main() {

	TreeProperties treeProp;

	struct Node *root = (struct Node*) malloc(sizeof(struct Node));

	*root = Node(1);
	root -> l = new Node(2);
	root -> l -> l = new Node(4);
	root -> l -> r = new Node(6);
	// root -> l -> r -> r = new Node(8);
	// root -> l -> r -> r -> r = new Node(9);
	root -> r = new Node(3);
	root -> r -> l = new Node(5);
	root -> r -> r = new Node(7);

	treeProp.getProperties(root);


	return 0;
}