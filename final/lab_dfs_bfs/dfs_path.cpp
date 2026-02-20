#include <bits/stdc++.h>
using namespace std;

int countT = 0;

void dfs(vector<vector<int>> &mat, vector<int> &res, vector<int> &visited, int cur, int stop) {
	
	visited[cur] = 1;
	res.push_back(cur);
	
	if (cur == stop) {
		for (int i : res) {
			cout << i << " ";
		}
		cout << endl;
		countT++;
	} else {
		for (int val : mat[cur]) {
			if (!visited[val]) {
				dfs(mat, res, visited, val, stop);
			}
		}
	}
	res.pop_back();
	visited[cur] = 0;
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
	
	int cur, stop;
	cin >> cur >> stop;
	dfs(mat, res, visited, cur, stop);
	
	cout << countT;
		
}