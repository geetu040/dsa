#include <iostream>
#include <vector>
using namespace std;

class Graph {
	int numVertices;
	vector<int>* adjList;
public:
	Graph(int numVertices) {
		this -> numVertices = numVertices;
		adjList = new vector<int>[numVertices];
	}
	void add_edge(int i, int j) {
		adjList[i].push_back(j);
		adjList[j].push_back(i);
	}
	void printGraph() {
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
};

int main() {

	Graph g(5);
	g.add_edge(0, 1);
	g.add_edge(3, 2);
	g.add_edge(3, 1);
	g.add_edge(4, 0);
	g.printGraph();
	
	return 0;
}