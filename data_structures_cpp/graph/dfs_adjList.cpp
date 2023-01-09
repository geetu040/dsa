#include <iostream>
#include <vector>
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
	// vector<int> visitied;
	// stack<int> exploring;
	bool* hasVisited;
public:
	Graph(int numVertices) {
		this -> numVertices = numVertices;
		adjList = new vector<int>[numVertices];
		hasVisited = new bool[numVertices];
		for (int i=0; i<numVertices; i++) {
			hasVisited[i] = false;
		}
	}
	void printGraph();
	void add_edge(int i, int j) {
		adjList[i].push_back(j);
		adjList[j].push_back(i);
	}
	void DFS(int v=0) {
		hasVisited[v] = true;
		cout << v << endl;

		vector<int>::iterator i;
		for (i = adjList[v].begin(); i!=adjList[v].end(); i++) {
			if (! hasVisited[*i] ) {
				DFS(*i);
			}
		}
	}
	// void DFS(int v=0) {
	// 	visitied.push_back(v);
		
	// 	cout << v << endl;
		
	// 	bool alread_exists = false;
	// 	for (int i=0; i<adjList[v].size(); i++) {
	// 		if (!contains(visitied, adjList[v][i])) {
	// 			exploring.push( adjList[v][i] );
	// 		}
	// 	}
		
	// 	if (exploring.empty()) {return;}
	// 	int to_visit_next = exploring.top();
	// 	exploring.pop();
	// 	DFS(to_visit_next);
	// }

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