#include <bits/stdc++.h>
using namespace std;

void floyD(vector<vector<int>> &dist, int V, vector<vector<int>> &next) {
	
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] != 1e9 && i != j) {
				next[i][j] = j;
			}
		}
	}
	
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				
				if (dist[i][k] != 1e9 && dist[k][j] != 1e9 &&
					dist[i][k] + dist[k][j] < dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						next[i][j] = next[i][k];
					}
			}
		}
	}
}

void printParent(int u, int v, vector<vector<int>> next) {
	cout << u;
	while (u != v) {
		u = next[u][v];
		cout << "->" << u;
	}
	cout << endl;
}

int main() {
	int n, ed; cin >> n >> ed;
	vector<vector<int>> mat(n, vector<int>(n, 1e9));
	
	int u,v,w;
	for (int i = 0; i < ed; i++) {
		cin >> u >> v >> w;
		mat[u][v] = w;
	}
	
	vector<vector<int>> next(n, vector<int>(n,-1));
	floyD(mat, n, next);
	printParent(0, 7, next);
}