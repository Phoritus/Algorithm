#include <bits/stdc++.h>
using namespace std;

typedef long long large;

int len(large  a) {
	return to_string(a).size();
}

large Multiply(large a, large b) {
	int n = max(len(a), len(b));
	if (n <= 1) return a * b;
	
	int m =  n/2;
	int pw = pow(10, m);
	large a1 = a / pw;
	large a2 = a % pw;
	large b1 = b / pw;
	large b2 = b % pw;
	
	large A = Multiply(a1, b1);
	cout << "A: " << A << endl;
	large B = Multiply(a2, b1);
	cout << "B: " << B << endl;
	large C = Multiply(a1, b2);
	cout << "C: " << C << endl;
	large D = Multiply(a2, b2);
	cout << "D: " << D << endl;
	
	for (int i = 0; i < 10; i++) cout << "-";
	cout << endl;
	return A * pow(10, 2*m) + (B + C) * pow(10, m) + D;
	
} 

int main() {
	large a = 4568; large b = 3275;
	large res = Multiply(a, b);

	cout << res;
}