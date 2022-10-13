#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *l, *r;
	Node (int data) {
		this->data = data;
		l = NULL;
		r = NULL;
	}
};
class BinaryTree {
public:
	Node* root;
	BinaryTree() {
		root = NULL;
	}
	void insert(int data) {
		root = insert(root, data);
	}
	void printTree() {
		printTree(root);
	}
	void deleteNode(int key) {
		root = deleteNode(root, key);
	}
	Node* deleteNode(Node* node, int key) {
		if (node == NULL) return node;
		if (key < node->data) {
			node->l = deleteNode(node->l, key);
		}
		else if (key > node->data) {
			node->r = deleteNode(node->r, key);
		}
		else {
			//  this is the item to be removed
			if (node->l == NULL && node->r == NULL) {
				// if the node is a leaf
				node = NULL;
			}
			else if (node->l == NULL && node->r) {
				// if node has one child i.e right child
				// cout << node->l->data << endl;
				node->data = node->r->data;
				node->r = deleteNode(node->r, node->data);
			}
			else if (node->r == NULL && node->l) {
				// if node has one child i.e left child
				node->data = node->l->data;
				node->l = deleteNode(node->l, node->data);
			}
			else {
				// if node has 2 children
				// finding the inorder leaf
				Node* current_node = node->l;
				while (current_node->r != NULL) {
					current_node = current_node->r;
				}
				node->data = current_node->data;
				deleteNode(node->l, node->data);
			}
		}
		return node;
	}
	Node* insert(Node* node, int data) {
		if (node == NULL)
			return new Node(data);
		if (data <= node->data)
			node->l = insert(node->l, data);
		else
			node->r = insert(node->r, data);
		return node;
	}
	void printTree(Node* node) {
		if (node == NULL)
			return;
		cout << node -> data << endl ;
		printTree(node->l);
		printTree(node->r);
	}
};


int main() {

	BinaryTree bt;
	bt.insert(50);
	bt.insert(25);
	bt.insert(75);
	bt.insert(10);
	bt.insert(60);
	bt.insert(100);
	bt.insert(65);

	bt.deleteNode(75);

	bt.printTree();


	return 0;
}