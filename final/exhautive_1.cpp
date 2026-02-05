#include <bits/stdc++.h>
using namespace std;


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Ecount = 0; int n;
void print_sol(vector<int> x, int end) {
	
	
	for (int i = 0; i < end; i++) {
		if (x[i] == 1 && x[i + 1] == 2 || x[i] == 2 && x[i + 1] == 1) {
			Ecount++;
		}
//		cout << x[i] << " ";
	}
//	cout << endl;
}

void permute(vector<int> &x, int start, int end) {
	if (start == end) {
		
		print_sol(x, end);
		return;	
	}
	
	for (int i = start; i < end; i++) {
		swap(&x[start], &x[i]);
		permute(x, start + 1, end);
		swap(&x[start], &x[i]);
	}
}


int main() {
	cin >> n;
	vector<int> x(n, 0);
	for (int i = 0; i < n; i++) {
		x[i] = i+1;
	}
	
	permute(x, 0, n);
	cout << Ecount;
 	
	
}