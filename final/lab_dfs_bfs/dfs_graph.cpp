#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &mat, vector<int> &res, vector<int> &visited, int s) {
	
	visited[s] = 1;
	res.push_back(s);
	
	for (int val : mat[s]) {
		if (!visited[val]) {
			dfs(mat, res, visited, val);
		}
	}
}

int main() {
	
	int n, edge;
	cin >> n >> edge;
	vector<vector<int>> mat(n+1);
	int u, v;
	
	for (int i = 0; i < edge; i++) {
		cin >> u >> v;
		// undirected graph
		mat[u].push_back(v);
		mat[v].push_back(u);
	}
	
	for (int i = 0; i <= n; i++) {
		if (mat[i].empty()) continue;	
		
	    cout << i << " : ";
	    for (int j : mat[i]) {
	        cout << j << " ";
	    }
	    cout << endl;
	}
	
	vector<int> res;
	vector<int> visited(n+1);
	
	int k;
	cin >> k;
	dfs(mat, res, visited, k);
	
	for (int val : res) cout << val << " ";
	
}