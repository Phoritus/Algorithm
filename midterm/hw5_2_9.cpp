#include <bits/stdc++.h>
using namespace std;

typedef long long large;

int len(large  a) {
	return to_string(a).size();
}

large Karatsuba(large a, large b) {
	int n = max(len(a), len(b));
	if (n <= 1) return a * b;
	
	int m =  n/2;
	int pw = pow(10, m);
	large a1 = a / pw;
	large a2 = a % pw;
	large b1 = b / pw;
	large b2 = b % pw;
	
	large A = Karatsuba(a1, b1);
	cout << "A: " << A << endl;;
	large B = Karatsuba(a2, b2);
	cout << "B: " << B << endl;
	large C = Karatsuba(a1 + a2, b1 + b2);
	cout << "C: " << C << endl;
	
	for (int i = 0; i < 10; i++) cout << "-";
	cout << endl;
	return A * pow(10, 2*m) + (C - A - B) * pow(10, m) + B;
	
} 

int main() {
	large a = 4568; large b = 3275;
	large res = Karatsuba(a, b);

	cout << res;
}