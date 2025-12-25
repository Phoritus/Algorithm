#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int>& A, int l, int r) {
	int p = A[l];
	int i = l; int j = r + 1;
	do {
		do {
			i++;
		} while (A[i] <= p);

		do {
			j--;
		} while (A[j] > p);
		swap(A[i], A[j]);
	} while (i < j);
	swap(A[i], A[j]);
	swap(A[l], A[j]);
	return j;
}

void QuickSort(vector<int>&A, int l, int r) {
	if (l < r) {
		int s = Partition(A, l, r);
		QuickSort(A, l, s-1);
		QuickSort(A, s+1, r);
	}
}


string convertToString(vector<int> A) {
	string ans = "";
	for (int v : A) {
		ans += to_string(v);
	}
	return ans;
}

void consecutiveStreak(string arr) {
	vector<int> count(10, 0);
	int global_count = 0; int current_count = 0;
	int len = arr.length();
	
	for (int i = 0; i < len; i++) {
		if (i > 0 && arr[i] == arr[i-1]) {
			current_count++;
		} else {
			current_count = 1;
		}
		
		int digit = arr[i] - '0';
		
		count[digit] = max(count[digit], current_count);
		global_count = max(global_count, current_count);
	}
	
	for (int i = 0; i < count.size(); i++) {
		if (count[i] == global_count) {
			cout << i << " ";
		}
		
	}
	cout << endl;
}

void printUnique(string arr) {
	int n = arr.length();
	for (int i = 0; i < n-1; i++) {
		if (arr[i] != arr[i+1]) {
			cout << arr[i];
		}
	}
	
	cout << arr[n-1];
}

int main() {
	int n; cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	
	QuickSort(A, 0, n-1);
	string ans = convertToString(A);
	cout << ans << endl;
	consecutiveStreak(ans);
	printUnique(ans);
}