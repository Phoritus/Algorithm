#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> A(n), B(n);
	
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	
	unordered_set<int> setA, notA;
	vector<int> union_ans, inter_ans;
	
	for (int v : A) {
		if (!setA.count(v)) {
			setA.insert(v);
			union_ans.push_back(v);
		}
	}
	
	for (int v : B) {
		if (setA.count(v)) {
			inter_ans.push_back(v);
 		} else {
			if (!notA.count(v)) {
				notA.insert(v);
				union_ans.push_back(v);
			}
		}
	}
	
	for (int v : inter_ans) cout << v << " ";
	cout << endl;
	for (int v : union_ans) cout << v << " ";
}