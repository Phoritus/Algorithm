#include <bits/stdc++.h>
using namespace std;

int k; vector<vector<int>> res;
int n = 5;

void dfs(int i, vector<int> &cur, int total, vector<int> &nums) {
	
	if (total == k) {
		res.push_back(cur);
		return;
	}
	if (i >= nums.size() || total > k) {
		return;
	}
	cur.push_back(nums[i]);
	dfs(i, cur, total + nums[i], nums);
	
	cur.pop_back();
	dfs(i + 1, cur, total, nums);
}

int main() {
	cin >> k;
	vector<int> nums(n, 0);
	vector<int> cur;
	for (int i = 0; i < n; i++) cin >> nums[i];
	dfs(0, cur, 0, nums);
	
	for (vector<int> val : res) {
		for (int i : val) {
			cout << i << " ";
		}
		cout << endl;
	}
}