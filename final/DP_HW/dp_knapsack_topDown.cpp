#include <bits/stdc++.h>
using namespace std;

int memo[1001][1001];
int topDown(vector<int> &w, vector<int> &v, int i, int j) {
	
	if (i == 0 || j == 0) return 0;
	
	if (memo[i][j] != 0) return memo[i][j];
	if (w[i] <= j) {
		memo[i][j] = max(v[i] + topDown(w, v,i - 1, j - w[i]),
						 topDown(w, v, i - 1, j));
	} else {
		memo[i][j] = topDown(w, v, i - 1, j);
	}
	
	return memo[i][j];
}

int main() {
	
	int max_w, n;
	cin >> max_w >> n;
	vector<int> w(n+1), v(n+1);
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	
	int sol = topDown(w, v, n, max_w);
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= max_w; j++) {
			cout << memo[i][j] << " ";
		}cout << "\n";
	}
	cout << sol;
}