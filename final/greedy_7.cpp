#include <bits/stdc++.h>
using namespace std;

struct Program{
	int st, end;
};

int main() {
	int n = 10;
	vector<Program> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i].st >> data[i].end;
	}
	
	sort(data.begin(), data.end(), [](Program a, Program b) {
		if (a.end == b.end) return a.st < b.st;
		return a.end < b.end;
	});
	
	int numCPU = 3;
	priority_queue<int, vector<int>, greater<int>> cpu;
	for (int i = 0; i < numCPU; i++) cpu.push(0);
	
	int count = 0;
	for (const auto& val : data) {
		int freetime = cpu.top();
		cpu.pop();
		
		if (freetime <= val.st) {
			cpu.push(val.end);
			count++;
		} else {
			cpu.push(freetime);
		}
	}
	
	cout << count;
}