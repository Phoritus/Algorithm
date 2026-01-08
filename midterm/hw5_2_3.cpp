#include <bits/stdc++.h>
using namespace std;


int Max_Subarray_Sum(int A[], int n) {
	if (n == 1) return A[0];
	
	int m = n/2;
	int Lmss = Max_Subarray_Sum(A, m);
	int Rmss = Max_Subarray_Sum(A + m, n - m);
	
	int lsum = -1000; int rsum = -1000;
	int sum = 0;
	
	for (int i = m; i < n; i++) {
		sum += A[i];
		rsum = max(rsum, sum);
	}
	sum = 0;
	for (int i = m - 1; i >= 0; i--) {
		sum += A[i];
		lsum = max(lsum, sum);
	}
	
	return max(max(lsum, rsum), lsum+rsum);
}

int main() {
	int arr[] = {16, -25, 2, -54, 36, 9, -12, 66};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout << Max_Subarray_Sum(arr, n);
}