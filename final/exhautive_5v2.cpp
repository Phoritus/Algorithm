#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> &nums, int target) {
	vector<int> dp(target + 1, target + 1); // 0..target
	dp[0] = 0;
	
	for (int i = 1; i <= target; i++) {
		for (int j = 0; j < nums.size(); j++) {
			
			if (nums[j] <= i) {
				dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
			}
		}
	}
	return (dp[target] > target) ? -1 : dp[target];
	
}

int main() {
	int target = 8;
	vector<int> rope = {2, 3, 5};
	int count = dfs(rope, target);
	cout << count;
}