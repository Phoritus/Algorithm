#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> A = {5, 15, -30, 10, -5, 40, 10};
	int maxSub = A[0];
	int curSum = 0; int n = A.size();
	
	for (int i = 0; i < n; i++) {
		if (curSum < 0) {
			curSum = 0;
		}
		curSum += A[i];
		maxSub = max(curSum, maxSub);
	};
	cout << maxSub;
}