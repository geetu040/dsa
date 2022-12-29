#include <iostream>
using namespace std;

template<class T>
class Vector {
private:
	struct Node {
		T data;
		Node* next;
		Node (T data) {
			this->data = data;
			next = NULL;
		}
	};
public:
	Node* root;
	Vector() {
		root = NULL;
	}
	bool isEmpty() {
		return root == NULL;
	}
	bool find(int data) {
		Node* temp = root;
		while (temp) {
			if (temp->data == data) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	int size() {
		Node* temp = root;
		int s = 0;
		while (temp) {
			s++;
			temp = temp->next;
		}
		return s;
	}
	T get(int i) {
		Node* temp = root;
		while (temp->next) {
			if (i-- == 0) {
				return temp->data;
			}
			temp = temp->next;
		}
		return temp->data;
	}
	void push_back(T data) {
		if (isEmpty()) {
			root = new Node(data);
			return;
		}
		Node* temp = root;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new Node(data);
	}
	void push_front(T data) {
		if (isEmpty()) {
			root = new Node(data);
			return;
		}
		Node* temp = new Node(data);
		temp->next = root;
		root = temp;
	}
	void pop_back() {
		if (!isEmpty()) {
			Node* parent = NULL;
			Node* temp = root;
			while (temp->next) {
				parent = temp;
				temp = temp->next;
			}
			delete temp;
			parent->next = NULL;
		}
	}
	void pop_front() {
		if (!isEmpty()) {
			Node* temp = root;
			root = root->next;
			delete temp;
		}
	}
	T front() {
		if (!isEmpty()) {
			return root->data;
		} else {
			return -1;
		}
	}
	T back() {
		if (!isEmpty()) {
			Node* temp = root;
			while (temp->next) {
				temp = temp->next;
			}
			return temp->data;
		} else {
			return -1;
		}
	}
	void print() {
		Node* temp = root;
		cout << "NULL";
		while (temp) {
			cout << " -> " << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}
};

template<class T>
class AdjList {
private:
	int numVertices;
	Vector<T>* list;
	Vector<int> visited;
	Vector<int> not_visited;
public:
	AdjList(int numVertices) {
		this->numVertices = numVertices;
		list = new Vector<T>[numVertices];
	}
	void add_edge(int i, int j) {
		list[i].push_back(j);
		list[j].push_back(i);
	}
	void printGraph() {
		for (int i=0; i<numVertices; i++) {
			cout << "Vertix " << i << ":  ";
			list[i].print();
		}
	}
	void search(int depth_first=1) {
		visited = Vector<int>();
		not_visited = Vector<int>();

		int v = 0;
		while (true) {
			cout << v << endl;
			visited.push_back(v);

			for (int i=0; i<list[v].size(); i++) {
				T data = list[v].get(i);
				if ( !visited.find(data) ) {
					if (depth_first) {
						// DFS
						not_visited.push_front(data);
					} else {
						// BFS
						not_visited.push_back(data);
					}
				}
			}

			if (not_visited.isEmpty()) {
				return;
			}
			while (visited.find(not_visited.front())) {
				not_visited.pop_front();
				if (not_visited.isEmpty()) {
					return;
				}
			}
			v = not_visited.front();
			not_visited.pop_front();
		}
	}
	void DFS() {
		search(0);
	}
	void BFS() {
		search(0);
	}
};


int main() {

	AdjList<float> g(5);

	g.add_edge(0, 1);
	g.add_edge(3, 2);
	g.add_edge(3, 1);
	g.add_edge(4, 0);

	g.printGraph();

	g.search(0);


}