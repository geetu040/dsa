#include <iostream>
using namespace std;

class Node {
public:
	int key;
	int height;
	Node* l;
	Node* r;
	Node (int key) {
		this->key = key;
		l = NULL;
		r = NULL;
		height = 0;
	}
};
class AVTTreeOp {
public:
	int height(struct Node *node) {
		if (node == NULL) 
			return 0;

		int hl, hr;
		hl = height(node->l);
		hr = height(node->r);

		return 1 + ((hl > hr) ? hl : hr) ; // here greater is taken from left or right
	}
	Node* leftRotate(Node* node) {
		int* extra_edged_data = NULL;
		if (node->r->l != NULL) {
			extra_edged_data = (int*) malloc(sizeof(int));
			*extra_edged_data = node->r->l->key;
		}

		Node* temp = node;
		node = node->r;
		temp->r = NULL;
		node->l = temp;

		if (extra_edged_data != NULL)
			node = insert(node, *extra_edged_data);

		return node;
	}
	Node* rightRotate(Node* node) {
		int* extra_edged_data = NULL;
		if (node->l->r != NULL) {
			extra_edged_data = (int*) malloc(sizeof(int));
			*extra_edged_data = node->l->r->key;
		}

		Node* temp = node;
		node = node->l;
		temp->l = NULL;
		node->r = temp;

		if (extra_edged_data != NULL)
			node = insert(node, *extra_edged_data);

		return node;
	}
	Node* insert(Node* node, int key) {
		if (node == NULL) 
			node = new Node(key);
		else if (key <= node->key) {
			node->l = insert(node->l, key);
		}
		else {
			node->r = insert(node->r, key);
		}

		// HEIGHT IMBALANCED
		int height_balance = height(node->l) - height(node->r);
		node->height = height_balance;
		if (height_balance > 1) {
			if (key > node->l->key) {
				// LR Insertion
				node->l = leftRotate(node->l);
				node = rightRotate(node);
			}
			else if (key < node->l->key) {
				// LL Insertion
				node = rightRotate(node);
			}
		}
		if (height_balance < -1) {
			if (key > node->r->key) {
				// RR Insertion
				node = leftRotate(node);
			}
			else if (key < node->r->key) {
				// RL Insertion
				node->r = rightRotate(node->r);
				node = leftRotate(node);
			}
		}

		return node;
	}
	void printTree(Node* node, string indent="", string title="Root") {
		if (node == NULL) return;
		cout << indent << title + " - " << node->key << "(" << node->height << ")" << endl;
		indent += "\t";
		if (node->l != NULL) {
			printTree(node->l, indent, "L");
		}
		if (node->r != NULL) {
			printTree(node->r, indent, "R");
		}
	}
};

int main() {

	AVTTreeOp op;

	Node* root = NULL;

	root = op.insert(root, 50);
	root = op.insert(root, 25);
	root = op.insert(root, 75);
	root = op.insert(root, 10);
	root = op.insert(root, 30);
	root = op.insert(root, 60);
	root = op.insert(root, 63);
	root = op.insert(root, 62);
	root = op.insert(root, 64);
	root = op.insert(root, 66);
	root = op.insert(root, 80);
	root = op.insert(root, 160);
	root = op.insert(root, -160);
	root = op.insert(root, 163);
	root = op.insert(root, -163);
	root = op.insert(root, 162);
	root = op.insert(root, -162);
	root = op.insert(root, 164);
	root = op.insert(root, -164);
	root = op.insert(root, 166);
	root = op.insert(root, -166);
	root = op.insert(root, 180);
	root = op.insert(root, -180);


	op.printTree(root);



	return 0;
}