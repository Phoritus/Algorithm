#include <bits/stdc++.h>
using namespace std;

long double countX = 0;
void print_sol(vector<char> x, int end) {
	for (char val : x) {
		cout << val << " ";
	}
	cout << endl;
}

void permute(vector<char> &x, int start, int end) {
	if (start == end) {
		countX++;
		print_sol(x, end);
		return;
	}
	for (int i = start; i < end; i++) {
		sort(x.begin() + start, x.end());
		swap(x[start], x[i]);
		permute(x, start + 1, end);
	}
}

int main() {
	
	int n; cin >> n;
	vector<char> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	cout << endl;
	
	sort(x.begin(), x.end());
	permute(x, 0, n);
	cout << endl << countX;
}