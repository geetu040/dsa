#include <iostream>
using namespace std;

class Graph {
public:
	bool **adjMatrix;
	int numVertices;
	Graph(int numVertices) {
		this->numVertices = numVertices;
		adjMatrix = new bool*[numVertices];
		for (int i=0; i<numVertices; i++) {
			adjMatrix[i] = new bool[numVertices];
			for (int j=0; j<numVertices; j++) {
				adjMatrix[i][j] = false;
			}
		}
	}
	void add_edge(int i, int j) {
		adjMatrix[i][j] = true;
		adjMatrix[j][i] = true;
	}
	void remove_edge(int i, int j) {
		adjMatrix[i][j] = false;
		adjMatrix[j][i] = false;
	}
	void toString() {
		for (int i=0; i<numVertices; i++) {
			for (int j=0; j<numVertices; j++) {
				cout << adjMatrix[i][j] << "  ";
			}
			cout << endl;
		}
	}
	~Graph() {
		for (int i=0; i<numVertices; i++) {
			delete[] adjMatrix[i];
		}
		delete[] adjMatrix;
	}



};

int main() {

	Graph g = Graph(10);
	g.add_edge(1, 3);
	g.add_edge(5, 3);
	g.add_edge(8, 9);
	g.remove_edge(8, 9);
	g.toString();

	return 0;
}