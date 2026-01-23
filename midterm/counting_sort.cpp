#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr = {16, 25, 2, 54, 36, 9, 12, 66};
	int size = arr.size();
	vector<int> ans(size, 0);
	int lower = 999; int upper = -999;
	for (int i : arr) {
		if (i < lower) {
			lower = i;
		}
		
		if (i > upper) {
			upper = i;
		}
		
	} 
	int n = upper - lower + 1;
	vector<int> D(n, 0);
	
	for (int i = 0; i < size; i++) {
		D[arr[i] - lower] += 1;
	}
	cout << D.size() << endl;
	cout << "Index from count: " << endl; 
	for (int val : D) {
		cout << val << " ";
	}
	
	for (int i = 1; i < n; i++) {
		D[i] = D[i-1] + D[i];
	}
	cout << "After accumulate: " << endl; 
	for (int val : D) {
		cout << val << " ";
	}
	for (int i = 0; i < size;i++) {
		int j = arr[i] - lower;
		ans[D[j] - 1] = arr[i];
		D[j] -= 1;
	}
	cout << endl;
	cout << "Final array: " << endl;
	for (int i : ans) cout << i << " ";
}