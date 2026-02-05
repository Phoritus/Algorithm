#include <bits/stdc++.h>
using namespace std;

int k; vector<vector<int>> res;
void print_sol(vector<int> x, vector<int> nums, int end) {
	
	int sum = 0;
	for (int i = 0; i < end; i++) {
		if (x[i] == 1) {
			sum += nums[i];
		}
	}
	vector<int> tmp;
	if (sum == k) {
		for (int i = 0; i < end; i++) {
			if (x[i] == 1) {
				tmp.push_back(nums[i]);
			}
		}
		res.push_back(tmp);
	}
}

void subset1(vector<int> &x, vector<int> nums, int l, int r) {
	if (l == r) {
		print_sol(x, nums, r);
	} else {
		x[l] = 1;
		subset1(x, nums, l + 1, r);
		x[l] = 0;
		subset1(x, nums, l + 1, r);
	}
}
int main() {
	int n = 5;
	cin >> k;
	vector<int> x(n, 0);
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) cin >> nums[i];
	subset1(x, nums, 0, n);

	for (vector<int> val : res) {
		for (int i : val) {
			cout << i << " ";
		}
		cout << endl;
	}
}