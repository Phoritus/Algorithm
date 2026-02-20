#include <bits/stdc++.h>
using namespace std;

int min_dist = INT_MAX;
vector<int> best_path;

void dfs_shortedW(vector<vector<pair<int, int>>> &mat, vector<int> &res, vector<int> &visited, int cur, int stop, int currWeight) {
	if (currWeight >= min_dist) return;
	
	if (cur == stop) {
		min_dist = currWeight;
		best_path = res;
		return;
	}
	
	visited[cur] = 1;
	for (auto &val : mat[cur]) {
		int v = val.first;
		int w = val.second;
		if (!visited[v]) {
			res.push_back(v);
			dfs_shortedW(mat, res, visited, v, stop, currWeight + w);
			res.pop_back();
		}
	}
	
	visited[cur] = 0;
}

int main() {
	
	int n, edge;
	cin >> n >> edge;
	vector<vector<pair<int, int>>> mat(n+1);
	int u, v, w;
	
	for (int i = 0; i < edge; i++) {
		cin >> u >> v >> w;
		// undirected graph
		mat[u].push_back({v, w});
		mat[v].push_back({u, w});
	}
	
	for (int i = 0; i <= n; i++) {
		if (mat[i].empty()) continue;	
		
	    cout << i << " : ";
	    for (auto &val : mat[i]) {
	        cout << "{" << val.first << "," << val.second << "} ";
	    }
	    cout << endl;
	}
	
	vector<int> res;
	vector<int> visited(n+1);
	
	int cur, stop;
	cin >> cur >> stop;
	dfs_shortedW(mat, res, visited, cur, stop, 0);
	
	cout << cur << " ";
	for (int val : best_path) cout << val << " ";	
}