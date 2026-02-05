#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> &nums, int target) {
	if (target == 0) return 0;
	
	int res = 1e9;
	for (int val : nums) {
		
		if (target - val >= 0) {
			res = min(res, 1 + dfs(nums, target - val)); // plus 1 for rope used
		}
	}
	return res;
}

int main() {
	vector<int> rope = {2, 3, 5};
	int target = 7;
	
	int value = dfs(rope, target);
	cout << "Min Rope: " << value;
}