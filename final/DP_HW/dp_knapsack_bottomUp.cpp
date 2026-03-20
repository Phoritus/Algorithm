#include <bits/stdc++.h>
using namespace std;

int bottomUp(vector<int> &w, vector<int> &v, int max_w) {
	int n = w.size();
	vector<vector<int>> memo(n+1, vector<int>(max_w+1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= max_w; j++) {
			if (i == 0 || j == 0) {
				memo[i][j] = 0;
			} else if (w[i] <= j) {
				memo[i][j] = max(v[i] + memo[i - 1][j - w[i]], memo[i - 1][j]);
			} else {
				memo[i][j] = memo[i - 1][j];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= max_w; j++) {
			cout << memo[i][j] << " ";
		}
		cout << "\n";
	}
	return memo[n - 1][max_w];
}

int main() {
	int max_w, n;
	cin >> max_w >> n;
	vector<int> w(n+1), v(n+1);
	
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	
	cout << bottomUp(w, v, max_w);
}