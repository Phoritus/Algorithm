#include <bits/stdc++.h>
using namespace std;

int bottomUp(int target, int n, vector<int> &arr) {
	vector<int> dp(target + 1);
	dp[0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int k = arr[i]; k <= target; k++) {
			dp[k] += dp[k - arr[i]];
		}
	}
	return dp[target];
}

int main() {
	int target, n; cin >> target >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << bottomUp(target, n, arr);
}