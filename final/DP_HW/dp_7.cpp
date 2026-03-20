#include <bits/stdc++.h>
using namespace std;

int memo[1001][1001];
int findSum(int i, int n, vector<int> &arr) {
	if (n == 0) return 0;
	if (i >= arr.size()) return -1e9;
	
	if (memo[i][n] != 0) return memo[i][n];
	int pick = -1e9;
	int cur_len = i + 1;
	
	if (cur_len <= n) {
		pick = arr[i] + findSum(i, n - cur_len, arr);
	}
	
	int notpick = findSum(i + 1, n, arr);
	memo[i][n] = max(pick, notpick);
	return memo[i][n];
}

int main() {
	
	int n; cin >> n;
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	cout << findSum(0, n, arr);
}