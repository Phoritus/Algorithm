#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr) {
	int n = arr.size();
	auto p = minmax_element(arr.begin(), arr.end());
	int lower = *p.first, upper = *p.second;
	int size = upper - lower + 1;
	
	vector<int> D(size);
	for (int i = 0; i < n; i++) D[arr[i] - lower]++;
	for (int i = 1; i < size; i++) D[i] += D[i-1];
	
	int j; vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		j = arr[i] - lower;
		ans[D[j] - 1] = arr[i];
		D[j]--;
	}
	arr = ans;
}

int main() {	
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	countingSort(arr);
	double total = 0.0;
	double curTotal = 0.0;
	
	for (int i = 0; i < n; i++) {
		curTotal += arr[i];
		total += curTotal;
	}
	
	double ans = total/double(n);
	printf("%.2f", ans);

}