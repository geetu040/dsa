#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool contains(vector<int> v, int key) {
	for (int i=0; i<v.size(); i++) {
		if (v[i] == key) {
			return true;
		}
	}
	return false;
}

class Graph {
	int numVertices;
	vector<int>* adjList;
	bool* hasVisited;
	queue<int> exploring_queue;
	stack<int> exploring_stack;
public:
	Graph(int numVertices) {
		this -> numVertices = numVertices;
		adjList = new vector<int>[numVertices];
		hasVisited = new bool[numVertices];
	}
	void add_edge(int i, int j) {
		adjList[i].push_back(j);
		adjList[j].push_back(i);
	}
	void printGraph();
	void DFS() {
		cout << "DFS Traversal: ";
		this->DFS(0);
		cout << endl;
	};
	void BFS() {
		cout << "BFS Traversal: ";
		this->BFS(0);
		cout << endl;
	};
	void DFS(int v);
	void BFS(int v);

};

int main() {

	Graph g(5);
	g.add_edge(0, 1);
	g.add_edge(3, 2);
	g.add_edge(3, 1);
	g.add_edge(4, 0);

	cout << "---------------" << endl;
	g.printGraph();
	cout << "---------------" << endl;

	g.BFS();
	g.DFS();
	
	return 0;
}

void Graph::printGraph() {
	for (int i=0; i<numVertices; i++) {
		cout << "Vertix " << i << ":  ";
		for (int j=0; j<adjList[i].size(); j++) {
			cout << adjList[i][j];
			if (j != adjList[i].size()-1) {
				cout << " -> ";
			}
		}
		cout << endl;
	}
}
void Graph::DFS(int v) {
	hasVisited[v] = true;
	cout << v << "  ";

	vector<int>::iterator i;
	for (i = adjList[v].begin(); i<adjList[v].end(); i++) {
		if ( !hasVisited[*i] ) {
			exploring_stack.push(*i);
		}
	}
	if (exploring_stack.empty()) {
		for (int i=0; i<numVertices; i++) {
			hasVisited[i] = false;
		}
		return;
	}
	int next_vertix = exploring_stack.top();
	exploring_stack.pop();
	DFS(next_vertix);
}
// DFS TRAVERSAL METHOD 2
// void Graph::DFS(int v) {
// 	hasVisited[v] = true;
// 	cout << v << "  ";

// 	vector<int>::iterator i;
// 	for (i = adjList[v].begin(); i!=adjList[v].end(); i++) {
// 		if (! hasVisited[*i] ) {
// 			DFS(*i);
// 		}
// 	}
// }
void Graph::BFS(int v) {
	hasVisited[v] = true;
	cout << v << "  ";

	vector<int>::iterator i;
	for (i = adjList[v].begin(); i<adjList[v].end(); i++) {
		if ( !hasVisited[*i] ) {
			exploring_queue.push(*i);
		}
	}
	if (exploring_queue.empty()) {
		for (int i=0; i<numVertices; i++) {
			hasVisited[i] = false;
		}
		return;
	}
	int next_vertix = exploring_queue.front();
	exploring_queue.pop();
	BFS(next_vertix);
}