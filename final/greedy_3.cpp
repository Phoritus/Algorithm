#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> start(n), end(n);
	
	for (int i = 0; i < n; i++) {
		cin >> start[i] >> end[i];
	}
	
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());
	
	int curCount = 0;
	int maxCount = INT_MIN;
	int i = 0, j = 0;
	while (i < n) {		
		if (start[i] < end[j]) {
			curCount++;
			i++;
		} else {
			curCount--;
			j++;
		}
		
		maxCount = max(maxCount, curCount);
	}	
	cout << maxCount;
}