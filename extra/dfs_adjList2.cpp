#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
	void push(int data) {
		if (!next) {
			next = new struct Node(data);
			return;
		}
		next->push(data);
	}
	void print() {
		cout << data << " -> ";
		if (next) {
			next->print();
		}

	}
};

class Graph {
	int numVertices;
	struct Node** adjList;
	bool* visited;
	stack<int> exploring;
public:
	Graph(int numVertices) {
		this -> numVertices = numVertices;
		adjList = new Node*[numVertices];
		visited = new bool[numVertices];
		for (int i=0; i<numVertices; i++) {
			adjList[i] = new Node(i);
		}
	}
	void add_edge(int i, int j) {
		adjList[i]->push(j);
		adjList[j]->push(i);
	}
	void printGraph() {
		for (int i=0; i<numVertices; i++) {
			cout << "Vertix : ";
			adjList[i]->print();
			cout << endl;
		}
	}
	bool all_visited() {
		for (int i=0; i<numVertices; i++) {
			if (visited[i] == 0) {
				return false;
			}
		}
		return true;
	}
	void DFS() {
		for (int i=0; i<numVertices; i++){
			visited[i] = false;
		}

		if (false) {
			// doing recursively
			DFS(0);
			return;
		}

		int v = 0;
		while (true) {
			cout << v << endl;
			visited[v] = true;
			Node* temp = adjList[v]->next;
			while (temp) {
				if (! visited[temp->data]) {
					exploring.push(temp->data);
				}
				temp = temp->next;
			}
			if (exploring.empty()) {
				break;
			}
			v = exploring.top();
			exploring.pop();
		}
	}
	void DFS(int v) {
		visited[v] = true;
		Node* temp = adjList[v]->next;
		while (temp) {
			if (!visited[temp->data]) {
				DFS(temp->data);
			}
			temp = temp->next;
		}
	}
};

int main() {

	Graph g(5);

	g.add_edge(0, 1);
	g.add_edge(3, 2);
	g.add_edge(3, 1);
	g.add_edge(4, 0);
	g.printGraph();

	g.DFS();
	
	return 0;
}