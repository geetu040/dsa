#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<vector<int>> graph, vector<vector<int>> visited, int next[], int r, int c) {
	int y = next[0];
	int x = next[1];

	if (x < 0 || x >= c)
		return false;
	if (y < 0 || y >= r)
		return false;
	if (graph[y][x] == 0)
		return false;
	if (visited[y][x] == 1)
		return false;

	return true;
}
void backtrack(vector<vector<int>> graph, vector<vector<int>> visited, int start[], int end[], int r, int c, string path, vector<string> paths) {

	if (start[0]==end[0] && start[1]==end[1]) {
		paths.push_back(path);
		cout << paths.size();
		cout << path << " ";
		return;
	}

	int up[] = {start[0]-1, start[1]};
	int left[] = {start[0], start[1]-1};
	int down[] = {start[0]+1, start[1]};
	int right[] = {start[0], start[1]+1};

	visited[start[0]][start[1]] = 1;
	if ( isSafe(graph, visited, up, r, c) ) {
		backtrack(graph, visited, up, end, r, c, path+"U", paths);
	}
	if ( isSafe(graph, visited, left, r, c) ) {
		backtrack(graph, visited, left, end, r, c, path+"L", paths);
	}
	if ( isSafe(graph, visited, down, r, c) ) {
		backtrack(graph, visited, down, end, r, c, path+"D", paths);
	}
	if ( isSafe(graph, visited, right, r, c) ) {
		backtrack(graph, visited, right, end, r, c, path+"R", paths);
	}
	visited[start[0]][start[1]] = 0;


}
vector<string> getPossiblePaths(vector<vector<int>> graph, int start[], int end[]) {
	vector<vector<int>> visited;
	vector<string> paths;

	int r = graph.size();
	int c = graph[0].size();

	for (int i=0; i<r; i++) {
		vector<int> temp;
		for (int j=0; j<c; j++) {
			temp.push_back(0);
		}
		visited.push_back(temp);
	}

	backtrack(graph, visited, start, end, r, c, "", paths);

	return paths;
}

int main() {


	vector<vector<int>> graph = {
		{1, 0, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 0},
		{1, 0, 1, 1, 1, 0},
		{1, 1, 1, 0, 1, 0},
		{1, 0, 0, 1, 1, 1},
	};

	int start[] = {0, 0};
	int end[] = {4, 5};

	vector<string> paths = getPossiblePaths(graph, start, end);

	cout << "\nPrinting\n";
	cout << paths.size() << endl;
	for (int i=0; i<paths.size(); i++) {
		cout << paths[i] << " ";
	}


	return 0;
}