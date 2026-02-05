#include <bits/stdc++.h>
using namespace std;

int maxV = INT_MIN; int maxW;
void print_sol(vector<int> &x, vector<int> &w, vector<int> &v) {
	int n = x.size();
	int sumW = 0;
	int sumV = 0;
	
	for (int i = 0; i < n; i++) {
		
		if (sumW > maxW) {
			return;
		}
		
		if (x[i] == 1) {
			sumW += w[i];
			sumV += v[i];
		}
	}
	
	if (sumW <= maxW) {
		maxV = max(maxV, sumV);
	}
}

void subset1(vector<int> &x, vector<int> &w, vector<int> &v, int l, int r) {
	
	if (l == r) {
		print_sol(x, w, v);
	} else {
		x[l] = 1;
		subset1(x, w, v, l + 1, r);
		x[l] = 0;
		subset1(x, w, v, l + 1, r);
	}
	
}

int main() {
	
	cin >> maxW;
	int n = 4; vector<int> x(n);
	vector<int> w(n); vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) cin >> w[i];
	
	subset1(x, w, v, 0, n);
	cout << "Max Value: " << maxV;
	
}