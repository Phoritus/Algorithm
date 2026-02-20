#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &mat, int cur) {
	
	int n = mat.size();
	vector<int> visited(n+1);
	queue<int> q;
	q.push(cur);
	visited[cur] = 1;
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (int val : mat[cur]) {
			int next = val;
			
			if (!visited[next]) {
				q.push(next);
				visited[next] = 1;
			}
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
		mat[u].push_back(v);
		mat[v].push_back(u);
	}
	
	for (int i = 0; i <= n; i++) {
		if (mat[i].empty()) continue;
				
		cout << i << " : ";
		for (int val : mat[i]) {
			cout << val << " ";
		}
		cout << endl;
	}
	
	int k;
	cin >> k;
	bfs(mat, k);
}